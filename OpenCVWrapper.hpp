#ifndef OpenCVWrapper_Header_h
#define OpenCVWrapper_Header_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import <CoreLocation/CoreLocation.h>
#import "define.h"

@interface OpenCVWrapper : NSObject
	- (int) detect: (UIImage *) image strAppType:(NSString *) strAppType nPhone:(int) nPhone nTagShape:(int) nTagShape;
	- (NSString *) retrunTagCode;
	- (void) setValue:  (bool) bLineProfile bCheckK10:(bool) bCheckK10 nHiddenCodeNum:(int) nHiddenCodeNum bRecognitionLevel:(bool) bRecognitionLevel nPixelMatchingLevel:(int) nPixelMatchingLevel;
    - (void) setResource : (int) nSize arr:(NSArray *) arr;
	- (void) setTagOptions : (NSArray *) arr;
	- (void) setCompareImages : (NSArray *) arr;
    - (NSString *) returnSerialNumber;
    - (NSString *) retrunGoodCnt;
    - (void) initGoodCnt;
@end

#endif
