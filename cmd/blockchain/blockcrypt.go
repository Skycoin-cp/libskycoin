package main


import (
    //"encoding/hex"
    //"errors"
    "fmt"
    "github.com/skycoin/skycoin/src/coin"
    //"github.com/skycoin/skycoin/src/keyring"

    "log"
    //"math/rand"
    "encoding/hex"
)


var master_pubkey coin.PubKey
var master_seckey coin.SecKey

func init() {
	seckey_hex := "5a42c0643bdb465d90bf673b99c14f5fa02db71513249d904573d2b8b63d353d"
    master_seckey := coin.SecKeyFromHex(seckey_hex)
    master_pubkey := PubKeyFromSecKey(seckey)
}

//sign a block with a private key
func SignBlock(block coin.Block, seckey coin.SecKey) (coin.Sig, error) {
	return coin.SignHash(block.HashHeader(), seckey)
}

//verify block signature
func VerifyBlockSignature(block coin.Block, sig Sig) error {
	return coin.VerifySignature(master_pubkey, sig, block.HashHeader())
}