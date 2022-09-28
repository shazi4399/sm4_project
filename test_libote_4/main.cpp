//
// Created by zhanghao on 22-9-27.
//
#include <iostream>
//#include "OT_Tests.h"
#include "OT_Tests.h"
//#include "Common.h"
#include "libOTe/TwoChooseOne/OTExtInterface.h"
#include "libOTe/Base/BaseOT.h"
#include "libOTe/Tools/Tools.h"
#include "libOTe/Tools/LinearCode.h"
#include <cryptoTools/Network/Channel.h>
#include <cryptoTools/Network/Session.h>
#include <cryptoTools/Network/IOService.h>
#include <cryptoTools/Common/Log.h>
#include <cryptoTools/Common/TestCollection.h>

#include "libOTe/TwoChooseOne/Iknp/IknpOtExtReceiver.h"
#include "libOTe/TwoChooseOne/Iknp/IknpOtExtSender.h"

#include "libOTe/TwoChooseOne/Kos/KosOtExtReceiver.h"
#include "libOTe/TwoChooseOne/Kos/KosOtExtSender.h"


#include "libOTe/TwoChooseOne/KosDot/KosDotExtReceiver.h"
#include "libOTe/TwoChooseOne/KosDot/KosDotExtSender.h"



//#include "libOTe/TwoChooseOne/SoftSpokenOT/SoftSpokenMalLeakyDotExt.h"
//#include "libOTe/TwoChooseOne/SoftSpokenOT/SoftSpokenMalOtExt.h"
//#include "libOTe/TwoChooseOne/SoftSpokenOT/SoftSpokenShDotExt.h"
//#include "libOTe/TwoChooseOne/SoftSpokenOT/SoftSpokenShOtExt.h"


#include "libOTe/NChooseOne/Kkrt/KkrtNcoOtReceiver.h"
#include "libOTe/NChooseOne/Kkrt/KkrtNcoOtSender.h"

#include "Common.h"
#include <thread>
#include <vector>
#include <random>
#include <cryptoTools/Common/BitVector.h>
#include <cryptoTools/Common/Matrix.h>

using namespace std;
using namespace osuCrypto;
//using namespace tests_libOTe;

inline auto eval(macoro::task<>& t0, macoro::task<>& t1)
{
    auto r = macoro::sync_wait(macoro::when_all_ready(std::move(t0), std::move(t1)));
    std::get<0>(r).result();
    std::get<1>(r).result();
}

void OT_100Receive_Test(BitVector& choiceBits, span<block> recv, span<std::array<block, 2>>  sender)
{

    for (u64 i = 0; i < choiceBits.size(); ++i)
    {

        u8 choice = choiceBits[i];
        const block& revcBlock = recv[i];
        //(i, choice, revcBlock);
        const block& senderBlock = sender[i][choice];

        if (i%10==0) {
            std::cout << "[" << i << ",0]--" << sender[i][0] << std::endl;
            std::cout << "[" << i << ",1]--" << sender[i][1] << std::endl;
            std::cout << (int)choice << "-- " << recv[i] << std::endl;
        }
        if (neq(revcBlock, senderBlock))
            throw UnitTestFail();

        if (eq(revcBlock, sender[i][1 ^ choice]))
            throw UnitTestFail();
    }

}
void OtExt_Iknp_Test()
{


    setThreadName("Sender");



        auto sockets = cp::LocalAsyncSocket::makePair();

        PRNG prng0(block(4253465, 3434565));
        PRNG prng1(block(42532335, 334565));

        u64 numOTs = 200;

        std::vector<block> recvMsg(numOTs), baseRecv(128);
        std::vector<std::array<block, 2>> sendMsg(numOTs), baseSend(128);
        BitVector choices(numOTs), baseChoice(128);
        choices.randomize(prng0);
        baseChoice.randomize(prng0);

        prng0.get((u8*)baseSend.data()->data(), sizeof(block) * 2 * baseSend.size());
        for (u64 i = 0; i < 128; ++i)
        {
            baseRecv[i] = baseSend[i][baseChoice[i]];
        }

        IknpOtExtSender sender;
        IknpOtExtReceiver recv;

        recv.setBaseOts(baseSend);
        auto proto0 = recv.receive(choices, recvMsg, prng0, sockets[0]);

        sender.setBaseOts(baseRecv, baseChoice);
        auto proto1 = sender.send(sendMsg, prng1, sockets[1]);
        eval(proto0, proto1);

        OT_100Receive_Test(choices, recvMsg, sendMsg);


    throw UnitTestSkipped("ENABLE_IKNP is not defined.");

}
int main(){
    OtExt_Iknp_Test();
    return 0;
}