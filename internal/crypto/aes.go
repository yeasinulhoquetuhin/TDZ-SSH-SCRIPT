package crypto

import (
    "crypto/aes"
    "crypto/cipher"
    "crypto/rand"
    "encoding/hex"
    "fmt"
    "io"
)

var key = []byte("TDZ-SuperSecure-32byteKey!2024!!")

func Encrypt(plaintext []byte) (string, error) {
    block, _ := aes.NewCipher(key)
    c := make([]byte, aes.BlockSize+len(plaintext))
    iv := c[:aes.BlockSize]
    io.ReadFull(rand.Reader, iv)
    stream := cipher.NewCFBEncrypter(block, iv)
    stream.XORKeyStream(c[aes.BlockSize:], plaintext)
    return hex.EncodeToString(c), nil
}

func Decrypt(hexData string) ([]byte, error) {
    data, _ := hex.DecodeString(hexData)
    block, _ := aes.NewCipher(key)
    if len(data) < aes.BlockSize {
        return nil, fmt.Errorf("too short")
    }
    iv := data[:aes.BlockSize]
    data = data[aes.BlockSize:]
    stream := cipher.NewCFBDecrypter(block, iv)
    stream.XORKeyStream(data, data)
    return data, nil
}
