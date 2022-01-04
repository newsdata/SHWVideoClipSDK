//
//  NSMutableArray+BPSafe.h
//  BeiPaiVideoEditor
//
//  Created by yehot on 2019/8/30.
//  Copyright © 2019 Xin Hua Zhi Yun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableArray (BPSafe)

- (void)bp_addObject:(nonnull id)object;

- (id)bp_objectAtIndex:(NSUInteger)index;
- (NSInteger)bp_indexOfObject:(id)obj;

- (void)bp_removeObjectAtIndex:(NSUInteger)index;

- (void)bp_insertObject:(id)anObject atIndex:(NSUInteger)index;

- (void)bp_removeObject:(id)obj;

@end

NS_ASSUME_NONNULL_END
