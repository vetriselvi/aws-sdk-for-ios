/*
 * Copyright 2010 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "../AmazonClientException.h"

#define kS3RegionUSWest1 @"us-west-1"
#define kS3RegionEU      @"EU"
#define kS3RegionAPSoutheast1  @"ap-southeast-1"

/**
 * Specifies constants that define Amazon S3 Regions.
 * <p>
 * Amazon S3 Regions allow the user to choose the geographical region where Amazon S3
 * will store the buckets the user creates. Choose a Amazon S3 Region to optimize
 * latency, minimize costs, or address regulatory requirements.
 * </p>
 * <p>
 * Objects stored in a Amazon S3 Region never leave that region unless explicitly
 * transfered to another region.
 * </p>
 */
@interface S3Region : NSObject {
	NSString *stringValue;
}

/** Returns an S3Region initialized with the supplied string value. */
-(id)initWithStringValue:(NSString *)value;

/**
 * The US Standard Amazon S3 Region. This region
 * uses Amazon S3 servers located in the United
 * States.
 * <p>
 * This is the default Amazon S3 Region. All requests sent to
 * <code>s3.amazonaws.com</code> go
 * to this region unless a location constraint is specified when creating a bucket.
 * The US Standard Region automatically places
 * data in either Amazon's east or west coast data centers depending on
 * which one provides the lowest latency. The US Standard Region
 * provides eventual consistency for all requests.
 * </p>
 */
+(S3Region *)USStandard;

/**
 * The US-West (Northern California) Amazon S3 Region. This region uses Amazon S3
 * servers located in Northern California.
 * <p>
 * When using buckets in this region, optionally set the client
 * endpoint to <code>s3-us-west-1.amazonaws.com</code> on all requests to these
 * buckets to reduce any latency experienced after the first
 * hour of creating a bucket in this region.
 * </p>
 * <p>
 * In Amazon S3, the US-West (Northern California) Region provides
 * read-after-write consistency for PUTS of new objects in Amazon
 * S3 buckets and eventual consistency for overwrite PUTS and DELETES.
 * </p>
 */
+(S3Region *)USWest;

/**
 * The EU (Ireland) Amazon S3 Region. This region uses Amazon S3 servers located
 * in Ireland.
 * <p>
 * In Amazon S3, the EU (Ireland) Region provides read-after-write
 * consistency for PUTS of new objects in Amazon S3 buckets and eventual
 * consistency for overwrite PUTS and DELETES.
 * </p>
 */
+(S3Region *)EUIreland;

/**
 * The Asia Pacific (Singapore) Region. This region uses Amazon S3 servers located
 * in Singapore.
 * <p>
 * When using buckets in this region, optionally set the client
 * endpoint to <code>s3-ap-southeast-1.amazonaws.com</code> on all requests to these buckets
 * to reduce any latency experienced after the first hour of
 * creating a bucket in this region.
 * </p>
 */
+(S3Region *)APSingapore;

/** Convert a string describing an Amazon S3 region to the corresponding S3Region
 *
 * @param regionName A string representation of an Amazon S3 region.
 * @return The corresponding S3Region.
 * @throws AWSClientException If the specified string does not match one of the Amazon S3 regions.
 */
+(S3Region *)regionWithString:(NSString *)regionName;

@end
