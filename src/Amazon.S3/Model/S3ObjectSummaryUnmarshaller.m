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

#import "S3ObjectSummaryUnmarshaller.h"

@implementation S3ObjectSummaryUnmarshaller


#pragma mark NSXMLParserDelegate implementation

- (void) parser:(NSXMLParser *)parser 
  didEndElement:(NSString *)elementName 
   namespaceURI:(NSString *)namespaceURI 
  qualifiedName:(NSString *)qName
{
	[super parser:parser didEndElement:elementName namespaceURI:namespaceURI qualifiedName:qName];
	
	if ([elementName isEqualToString:@"Key"]) {
		self.summary.key = self.currentText;
		return;
	}
	
	if ([elementName isEqualToString:@"ETag"]) {
		self.summary.etag = self.currentText;
		return;
	}	
	
	if ([elementName isEqualToString:@"Contents"]) {
		if (caller != nil) {
			[parser setDelegate:caller];
		}
		
		if (parentObject != nil && [parentObject respondsToSelector:parentSetter]) {
			[parentObject performSelector:parentSetter withObject:self.summary];
		}
		
		return;
	}	
}


#pragma mark Unmarshalled object property

-(S3ObjectSummary*)summary
{
	if (nil == summary)
	{
		summary = [[S3ObjectSummary alloc] init];
	}
	return summary;
}

-(void)dealloc
{
	[summary release];
	[super dealloc];
}

@end

