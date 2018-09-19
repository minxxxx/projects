package com.qr_generator;

import android.util.Base64;

import java.io.UnsupportedEncodingException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

/**
 * Created by Owen on 2017/09/30.
 */

public class CryptoHelper {
    private Key _key;

    private static final byte[] iv = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    public CryptoHelper() {}

    public CryptoHelper(Key key) {
        this._key = key;
    }

    public static String encrypt(String value, String key)
        throws NoSuchAlgorithmException, NoSuchPaddingException,
            InvalidKeyException, IllegalBlockSizeException,
            BadPaddingException, UnsupportedEncodingException,
            InvalidAlgorithmParameterException
    {
        SecretKey secKey = new SecretKeySpec(key.getBytes("UTF-8"), "AES");
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, secKey, new IvParameterSpec(iv));
        byte[] newData = cipher.doFinal(value.getBytes());
        return (Base64.encodeToString(newData, Base64.NO_WRAP));
    }

    public static String decrypt(String value, String key)
        throws NoSuchAlgorithmException, NoSuchPaddingException,
            InvalidKeyException, IllegalBlockSizeException,
            BadPaddingException, UnsupportedEncodingException,
            InvalidAlgorithmParameterException
    {
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        SecretKey secKey = new SecretKeySpec(key.getBytes("UTF-8"), "AES");

        cipher.init(Cipher.DECRYPT_MODE, secKey, new IvParameterSpec(iv));
        byte[] newData = cipher.doFinal(Base64.decode(value, Base64.NO_WRAP));
        return (new String(newData));
    }
}
