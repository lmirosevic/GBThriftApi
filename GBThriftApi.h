//
//  GBThriftApi.h
//  GBThriftApi
//
//  Created by Luka Mirosevic on 18/05/2014.
//  Copyright (c) 2014 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "GoonbeeShared.h"

typedef void(^GBThriftCallCompletionBlock)(enum GBSharedResponseStatus status, id result, BOOL cancelled);

@interface GBThriftApi : NSObject

+(instancetype)sharedApi;
-(void)connectToServer:(NSString *)server port:(NSUInteger)port;

// subclasses should call this to execute the actual calls
-(void)callAPIMethodWithSelector:(SEL)selector block:(GBThriftCallCompletionBlock)block arguments:(void *)argument, ... NS_REQUIRES_NIL_TERMINATION;

// subclasses must override this and return the class which implements the thrift service
+(Class)thriftServiceClass;

@end
