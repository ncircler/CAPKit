@class LuaHelper;

@interface AppSandbox : DefaultSandbox <AppSandboxInterface>

@property (nonatomic, weak, readonly) GlobalSandbox *globalSandbox;
@property (nonatomic, readonly) LuaHelper *helper;
@property (nonatomic, readonly) ScreenScale *scale;
@property (nonatomic, readonly) id<AppLifecycle> lifecycle;
@property (nonatomic, readonly) NSMutableString *luaPath;
@property (nonatomic, readonly) NSString *dataPath DEPRECATED_ATTRIBUTE;
@property (nonatomic, readonly) NSString *appPath DEPRECATED_ATTRIBUTE;
@property (nonatomic, strong) ManifestM *manifest;
@property (nonatomic, readonly) NSMutableArray *pageList;
@property (nonatomic, readonly) LuaState *state;
@property (nonatomic, readonly) NSMutableArray *libraryPaths;
@property (nonatomic, readonly) NSMapTable *weakFunctions;
//@property (nonatomic, assign) int envRef;

- (id) initWithGlobalSandbox: (GlobalSandbox *) sandbox withManifest: (ManifestM *) m withAppPath: (NSString *) path withDataPath: (NSString *) dpath;

- (NSURL *) resolveFile: (NSString *) path;

- (NSString *) getDataFile: (NSString *) path;

- (void) reloadLuaPath;

- (GlobalSandbox *) getGlobalSandbox;

- (AppSandbox *) getAppSandbox;

- (NSInteger) getWidgetCount;

@end