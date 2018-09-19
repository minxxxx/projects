package com.qr_generator;

import android.graphics.Bitmap;
import android.os.Environment;
import android.util.Base64;
import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.react.uimanager.IllegalViewOperationException;
import com.google.zxing.BarcodeFormat;
import com.google.zxing.MultiFormatWriter;
import com.google.zxing.WriterException;
import com.google.zxing.common.BitMatrix;
import com.journeyapps.barcodescanner.BarcodeEncoder;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.security.Key;

/**
 * Created by Owen on 2017/09/29.
 */

@ReactModule(name = "QRCodeAndroid")
public class QRCodeModule extends ReactContextBaseJavaModule{

    private String imageBase64 = "";

    public QRCodeModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    public String getName() { return "QRCodeAndroid"; }

    private void saveQRImage(Bitmap bitmap) {
        String root = Environment.getExternalStorageDirectory().toString();
        root += "/Pictures/ERQR";
        File myDir = new File(root);
        myDir.mkdirs();
        String fName = "QRImage.png";
        File file = new File(myDir, fName);
        if (file.exists()) file.delete();
        Log.i("LOAD", root + fName);
        try {
            FileOutputStream out = new FileOutputStream(file);
            bitmap.compress(Bitmap.CompressFormat.PNG, 100, out);
            out.flush();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void convertToBase64(Bitmap bitmap) {
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        bitmap.compress(Bitmap.CompressFormat.PNG, 100, byteArrayOutputStream);
        byte[] byteArray = byteArrayOutputStream.toByteArray();

        imageBase64 = Base64.encodeToString(byteArray, Base64.DEFAULT);
        imageBase64 = imageBase64.replace("\n", "");
    }

    @ReactMethod
    public void createQRCode(String value, int height, int width, Promise promise) {
        MultiFormatWriter multiFormatWriter = new MultiFormatWriter();
        try {

            BitMatrix bitMatrix = multiFormatWriter.encode(value, BarcodeFormat.QR_CODE, width, height);
            BarcodeEncoder barcodeEncoder = new BarcodeEncoder();
            Bitmap bitmap = barcodeEncoder.createBitmap(bitMatrix);

            saveQRImage(bitmap);
            convertToBase64(bitmap);

            WritableMap map = Arguments.createMap();
            map.putString("QRCodeBase64", imageBase64);
            promise.resolve(map);
        } catch (IllegalViewOperationException e) {
            promise.reject("E_LAYOUT_ERROR", e);
        } catch (WriterException e) {
            promise.reject("E_QRGEN_ERROR", e);
        } catch (Exception e) {
            promise.reject("E_ENCRYPT_ERROR", e);
        }
    }
}
