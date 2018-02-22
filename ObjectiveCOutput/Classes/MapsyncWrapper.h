#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>
#import <MapsyncLib/MapsyncLib-Swift.h>
#import <ARKit/ARKit.h>
@class MapSession;
@class ARSession;

typedef NS_ENUM(NSInteger, Mode)
{
    ModeUnknown = 0,
    ModeMapping = 1,
    ModeLocalization = 2,
};

@interface MapsyncWrapper : NSObject

+ (instancetype)sharedInstanceWithARSession:(ARSession *)session mapMode:(Mode)mode appId:(NSString*) appId mapId: (NSString*) mapId userId:(NSString*) userId developerKey: (NSString*) developerKey;

+ (instancetype)sharedInstance;

+ (void)setUnityCallbackGameObject:(NSString*)objectName;
+ (void)setAssetLoadedCallbackFunction:(NSString*)functionName;
+ (void)setStatusUpdatedCallbackFunction:(NSString*)functionName;
+ (void)setStorePlacementCallbackFunction:(NSString*)functionName;

- (instancetype)initWithARSession:(ARSession *)session appId:(NSString*) appId mapId: (NSString*) mapId userId:(NSString*) userId developerKey: (NSString*) developerKey;

- (void)uploadAssetWithID:(NSString *)assetID position:(SCNVector3)position orientation:(CGFloat)orientation;

- (void)updateWithFrame:(ARFrame*)frame;

@end

