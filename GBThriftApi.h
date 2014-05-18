//
//  GBThriftApi.h
//  GBThriftApi
//
//  Created by Luka Mirosevic on 18/05/2014.
//  Copyright (c) 2014 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

// The following line requires the Goonbee Shared Thrift service. This library goes hand in hand with the this shared service as it provides common error handling for calls used by this library. You should write a library for your service/API and in the trift IDL include the "Goonbee Thrift Shared" (https://github.com/lmirosevic/Goonbee-Thrift-Shared) library, then when building your own library for your service, make sure to include, compile and link your project against the GoonbeeShared.{h,m} files. See GBChat for an example (https://github.com/lmirosevic/GBChat).
#import "GoonbeeShared.h"

typedef void(^GBThriftCallCompletionBlock)(enum GBSharedResponseStatus status, id result, BOOL cancelled);

@interface GBThriftApi : NSObject

/**
 * Returns a singleton for the API library.
 */
+(instancetype)sharedApi;

/**
 * Opens a connection to the server.
 * You must call this method before making any API calls.
 */
-(void)connectToServer:(NSString *)server port:(NSUInteger)port;

/**
 * Subclasses should write beautiful idiomatic calls which then internally call this method which executes the actual call and does all the magic for error handling, automatic retries, etc.
 */
-(void)callAPIMethodWithSelector:(SEL)selector block:(GBThriftCallCompletionBlock)block arguments:(void *)argument, ... NS_REQUIRES_NIL_TERMINATION;

/**
 * The return value of this method is used to instantiate the thrift class.
 * Subclasses must override this method and return the class which implements the thrift service which they are implementing.
 */
+(Class)thriftServiceClass;

@end
