//
// Created by zhanghao on 22-9-28.
//
#include <iostream>
#include <cryptoTools/Network/Channel.h>
#include <cryptoTools/Network/Session.h>
#include <cryptoTools/Network/IOService.h>
#include <cryptoTools/Common/Log.h>
#include <cryptoTools/Common/BitVector.h>
#include <cryptoTools/Crypto/PRNG.h>
#include <libOTe/Base/BaseOT.h>
#include <libOTe/TwoChooseOne/OTExtInterface.h>
#include <libOTe/TwoChooseOne/Iknp/IknpOtExtReceiver.h>
#include <libOTe/TwoChooseOne/Iknp/IknpOtExtSender.h>

using namespace std;
using namespace osuCrypto;

void Client_s(){
    // https://github.com/siamumarArchivedRepos/test-libOTE
    cout << "in client" << endl;
    IOService ios;
    Session ep(ios, "localhost", 1212, SessionMode::Client);
    Channel chl = ep.addChannel();

    PRNG prng(_mm_set_epi32(4253465, 3434565, 234435, 23987045));

    IknpOtExtReceiver receiver;
    DefaultBaseOT base;
    uint64_t baseCount = 128;
    vector<array<block, 2>> baseMsg(baseCount);
    base.send(baseMsg, prng, chl, 1);
    receiver.setBaseOts(baseMsg, prng, chl);

    uint64_t num_OTs = 1024;
    vector<block> recvMsgs(num_OTs);
    BitVector bv(num_OTs);
    bv.randomize(prng);
    receiver.receive(bv, recvMsgs, prng, chl);

    cout << "done OT" << endl;
}

int main(){
    Client_s();
    return 0;
}