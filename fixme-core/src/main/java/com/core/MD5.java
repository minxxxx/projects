package com.core;

import javax.xml.bind.DatatypeConverter;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5 {
    public static String createMD5(String id) {
        String myHash = "error_checksum";
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(id.getBytes());
            byte[] bytesDigest = md.digest();
            myHash = DatatypeConverter.printHexBinary(bytesDigest).toLowerCase();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return myHash;
    }
}
