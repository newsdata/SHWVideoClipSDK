//
//  MGCPixelBufferDelegate.h
//  Runner
//
//  Created by yehot on 2019/12/14.
//  Copyright © 2019 The Chromium Authors. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BPRenderable.h"

@protocol MGCPixelBufferDelegate <NSObject>

- (void)videoRender:(id<BPVideoRenderable>)render displayPixelbuffer:(CVPixelBufferRef)pixelbuffer;

@end
