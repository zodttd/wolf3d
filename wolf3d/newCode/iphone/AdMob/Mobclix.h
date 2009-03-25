//Mobclix Library Version 1.1.0

typedef enum{
	APPLICATION_TYPE_DEBUG = 0, 
	APPLICATION_TYPE_BETA = 1,
	APPLICATION_TYPE_PROD = 2 
} MobclixApplicationType;

typedef enum{
	LOG_LEVEL_DEBUG =	1 << 0,
	LOG_LEVEL_INFO =	1 << 1,
	LOG_LEVEL_WARN	=	1 << 2,
	LOG_LEVEL_ERROR	=	1 << 3,
	LOG_LEVEL_FATAL =	1 << 4
} MobclixLogLevel;

typedef enum {
	FW_NS_OBJECT				= 0,
		
	FW_TOUCH_LAYER				= 1 << 17,
		FW_ADDRESS_BOOK_UI		= 1 << 0,
		FW_UI_KIT				= 1 << 1,
		
	FW_MEDIA_LAYER				= 1 << 18,
		FW_AUDIO_TOOLBOX		= 1 << 2,
		FW_AUDIO_UNIT			= 1 << 3,
		FW_CORE_AUDIO			= 1 << 4,
		FW_CORE_GRAPHICS		= 1 << 5,
		FW_MEDIA_PLAYER			= 1 << 6,
		FW_OPEN_GL_ES			= 1 << 7,
		FW_QUARTZ_CORE			= 1 << 8,
		
	FW_CORE_SERVICES_LAYER		= 1 << 19,
		FW_ADDRESS_BOOK			= 1 << 9,
		FW_CORE_FOUNDATION		= 1 << 10,
		FW_CORE_LOCATION		= 1 << 11,
		FW_FOUNDATION			= 1 << 12,
		FW_SYSTEM_CONFIGURATION	= 1 << 13,
		
	FW_CORE_OS_LAYER			= 1 << 20,
		FW_CF_NETWORK			= 1 << 14,
		FW_SECURITY				= 1 << 15,
		FW_SYSTEM				= 1 << 16
} AppleFrameWorkCode;

typedef enum  {
	RATING_NONE			= 0,
	RATING_POOR			= 1,
	RATING_FAIR			= 2,
	RATING_GOOD			= 3,
	RATING_VERY_GOOD	= 4,
	RATING_EXCELLENT	= 5
} MobclixRating;

@interface Mobclix : NSObject {
}

+ (void) startApplicationWithId: (NSString*) applicationId
				applicationType: (MobclixApplicationType) applicationType
			applicationLogLevel: (MobclixLogLevel) applicationLogLevel
				 recordLocation: (BOOL) recordLocation
					 notifyUser: (BOOL) notifyUser;

+ (void) endApplication;

+ (void) logEventWithLevel: (MobclixLogLevel) logLevel
			   processName: (NSString*) processName
				 eventName: (NSString*) eventName
			   description: (NSString*) description
			appleFramework: (NSInteger) appleFramework
					  stop: (BOOL) stopProcess;

+ (void) comment: (NSString*)comment;

+ (void) ratingWithUsability: (MobclixRating)usability
				  appearance: (MobclixRating)appearance
						 fun: (MobclixRating)fun					
					   value: (MobclixRating)value
			  recommendation: (MobclixRating)recommendation
				 performance: (MobclixRating)performance
					 overall: (MobclixRating)overall;

+ (void) sync;

@end

