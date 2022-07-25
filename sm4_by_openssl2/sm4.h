//
// Created by zhanghao on 22-7-25.
//

//sm4.h
#ifndef _SM4_H_
#define _SM4_H_

#include <stdint.h>

#define SM4_BLOCK_SIZE       (16)

typedef struct
{
    void *ctx;
    void *key;
    void *iv;
    void *mode;
}sm4_data_t;

#define SM4_MODE_ECB	"0_ecb"
#define SM4_MODE_CBC	"1_cbc"
#define SM4_MODE_CFB	"2_cfb"
#define SM4_MODE_CTR    "3_ctr"

int32_t show_hex(int8_t* title, void* buf, uint32_t total);
int32_t sm4_gen_key(sm4_data_t *data, uint8_t *key, uint32_t length);
int32_t sm4_gen_iv(sm4_data_t *data, uint8_t *iv, uint32_t length);

int32_t sm4_encrypt_data(sm4_data_t *data, void *in, uint32_t ilen, void *out, uint32_t *olen);
int32_t sm4_decrypt_data(sm4_data_t *data, void *in, uint32_t ilen, void *out, uint32_t *olen);

int32_t sm4_data_init(sm4_data_t *data, void *mode);
int32_t sm4_data_exit(sm4_data_t *data);

#endif

