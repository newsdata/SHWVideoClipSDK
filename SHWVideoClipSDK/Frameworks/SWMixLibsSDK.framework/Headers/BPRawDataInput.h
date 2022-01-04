//
//  BPRawDataInput.h
//  JianBei
//
//  Created by yehot on 2019/10/7.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import "GPUImageOutput.h"
#import "GPUImageRawDataInput.h"

@interface BPRawDataInput : GPUImageOutput
{
    CGSize uploadedImageSize;
    
    dispatch_semaphore_t dataUpdateSemaphore;
}

// Initialization and teardown
- (id)initWithBytes:(GLubyte *)bytesToUpload size:(CGSize)imageSize pixelFormat:(GPUPixelFormat)pixelFormat;


/** Input data pixel format
 */
@property (readwrite, nonatomic) GPUPixelFormat pixelFormat;
@property (readwrite, nonatomic) GPUPixelType   pixelType;

// Image rendering
- (void)updateDataFromBytes:(GLubyte *)bytesToUpload size:(CGSize)imageSize;
- (void)processData;
- (void)processDataForTimestamp:(CMTime)frameTime;
- (CGSize)outputImageSize;


@end
