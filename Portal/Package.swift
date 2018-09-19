// swift-tools-version:4.0
import PackageDescription

let package = Package(
    name: "WeThinkCode_",
    dependencies: [
      .package(url: "https://github.com/IBM-Swift/Kitura.git", .upToNextMinor(from: "2.4.0")),
      .package(url: "https://github.com/IBM-Swift/HeliumLogger.git", .upToNextMinor(from: "1.7.1")),
      .package(url: "https://github.com/IBM-Swift/CloudEnvironment.git", from: "8.0.0"),
      .package(url: "https://github.com/RuntimeTools/SwiftMetrics.git", from: "2.0.0"),
      .package(url: "https://github.com/IBM-Swift/Health.git", from: "1.0.0"),
      .package(url: "https://github.com/IBM-Swift/Kitura-CouchDB.git", .upToNextMinor(from: "2.1.0")),
    ],
    targets: [
      .target(name: "WeThinkCode_", dependencies: [ .target(name: "Application"), "Kitura" , "HeliumLogger", "CouchDB"]),
      .target(name: "Application", dependencies: [ "Kitura", "CloudEnvironment","SwiftMetrics","Health",     ]),

      .testTarget(name: "ApplicationTests" , dependencies: [.target(name: "Application"), "Kitura","HeliumLogger" ])
    ]
)
