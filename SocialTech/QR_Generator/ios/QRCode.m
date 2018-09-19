//
//  QRCode.m
//  QR_Generator
//
//  Created by Owen EXALL on 2017/10/06.
//  Copyright © 2017 Facebook. All rights reserved.
//

#import "QRCode.h"
#import <Foundation/Foundation.h>

@implementation QRCodeiOS

RCT_EXPORT_MODULE();

- (CIImage *)createQRFromString:(NSString*)value {
  NSData *stringData = [value dataUsingEncoding:NSUTF8StringEncoding];
  CIFilter *qrFilter = [CIFilter filterWithName:@"CIQRCodeGenerator"];
  
  [qrFilter setValue:stringData forKey:@"inputMessage"];
  [qrFilter setValue:@"M" forKey:@"inputCorrectionLevel"];

  return qrFilter.outputImage;
}

- (UIImage *)createUIImageFromCIImage:(CIImage*)qrCode withScale:(CGFloat)scale {
  CGImageRef cgImage = [[CIContext contextWithOptions:nil]createCGImage:qrCode fromRect:qrCode.extent];
  
  UIGraphicsBeginImageContext(CGSizeMake(qrCode.extent.size.width * scale, qrCode.extent.size.height * scale));
  CGContextRef context = UIGraphicsGetCurrentContext();
  
  CGContextSetInterpolationQuality(context, kCGInterpolationNone);
  CGContextDrawImage(context, CGContextGetClipBoundingBox(context), cgImage);
  
  UIImage *scaledImage = UIGraphicsGetImageFromCurrentImageContext();
  
  UIGraphicsEndImageContext();
  CGImageRelease(cgImage);
  
  UIImage *flippedImage = [UIImage imageWithCGImage:[scaledImage CGImage]
                                              scale: scaledImage.scale
                                        orientation:UIImageOrientationDownMirrored];
  
  return (flippedImage);
}

- (NSString*)encodeToBase64String:(UIImage*)image {
  return [UIImagePNGRepresentation(image) base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
}


RCT_REMAP_METHOD(createQRCode,
				 value:(NSString*)value
				 findEventsWithResolver:(RCTPromiseResolveBlock)resolve
				 rejecter:(RCTPromiseRejectBlock)reject) {
  NSString *base64 = NULL;
  
  CIImage* qrCode = [self createQRFromString:value];
  UIImage* uIImage = [self createUIImageFromCIImage:qrCode withScale:2*[[UIScreen mainScreen] scale] ];
  
  UIImageWriteToSavedPhotosAlbum(uIImage, nil, nil, nil);
  
  base64 = [self encodeToBase64String:uIImage];
  
	if (base64) {
		resolve(base64);
	} else {
		reject(@"No Base 64 String", @"There was no string.", NULL);
	}
}


@end
