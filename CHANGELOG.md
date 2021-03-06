# JudoKit Objective-C SDK changelog

For the latest SDK changes, please see the [Github release page](https://github.com/Judopay/JudoKitObjC/releases).

## [6.2.6](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.2.6)
Released on 2016-11-09

#### Added
- Added in version 2.0.4 of JudoShield.
- Removed call to JudoShield to get current location.

## [6.2.5](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.2.5)
Released on 2016-11-01

#### Added
- SDK now supports Xcode8 and Swift 3

## [6.2.4](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.2.4)
Released on 2016-10-25

#### Added
- Latest version of JudoShield
- Device signals are now encrypted

## [6.2.3](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.2.3)
Released on 2016-09-20

#### Added
- Latest version of JudoShield

## [6.2.2](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.2.2)
Released on 2016-09-14

#### Added
- Latest version of JudoShield
- Minor bug fixes.

## [6.2.1](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.2.1)
Released on 2016-06-29

#### Added
- Added a navigation bar title color to the Theme object.
- SDK now detects if device is jailbroken.

## [6.1.0](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.1.0)
Released on 2016-06-02

#### Changed
- Injected card details are not masked and can be changed by the user
- Transaction gets created at initialization to enable adding and removing of custom information.
- Statically accessible version number instead of polling for bundle due to an issue with CocoaPods.

---

## [6.0.2](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.0.2)
Released on 2016-05-06

#### Added
- UI Test for Maestro token payment.
- A feature to initiate input into card and security card textfields with the Apple keyboard instead of 3rd party keyboard providers to ensure user security.
- UI and Integration tests for dedup.

#### Changed
- Injected card information is now shown with masking the card number.
- Camel case for 'ID'.

#### Removed
- Unused code
- TODO flags

#### Fixed
- An issue where deleting the slash in a date input field would result in unexpected behavior.
- An issue where the sdk would assume a token payment when card details were be injected (eg. by card scanning).
- An issue where injected card info would not appear correctly.
- An issue where the wrong error was returned for multiple payments with identical payment reference.
- Some issues with the UI and integration tests around deduplication.

---

## [6.0.1](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.0.1)
Released on 2016-04-28

#### Added
- Added a method that recursively searches for the currently active and visible ViewController.

#### Changed
- The deviceDNA will now be attached to the HTTP Request Body of any Transaction.

---

## [6.0.0](https://github.com/JudoPay/JudoKitObjC/releases/tag/6.0.0)
Released on 2016-04-20

#### Added
- Initial release
	- Added by [Hamon Ben Riazy](https://github.com/ryce).
