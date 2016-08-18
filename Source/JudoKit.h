//
//  JudoKit.h
//  JudoKitObjC
//
//  Copyright (c) 2016 Alternative Payments Ltd
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import <Foundation/Foundation.h>

#import "JPTransactionData.h"

static NSString * __nonnull const JudoKitVersion = @"6.2.1";

@class JPSession;

@class JudoPayViewController;

@class JPPayment, JPPreAuth, JPRegisterCard, JPTransaction;
@class JPCollection, JPVoid, JPRefund;
@class JPReceipt;

@class JPCardDetails;
@class JPPaymentToken;

@class JPTheme;

@class JPAmount;
@class JPReference;
@class JPPagination;
@class JPResponse;

/**
 *  Entry point for interacting with judoKit
 */
@interface JudoKit : NSObject

/**
 *  JudoKit api session
 */
@property (nonatomic, strong, readonly) JPSession * _Nonnull apiSession;

/**
 *  the theme of any judoSession
 */
@property (nonatomic, strong) JPTheme * _Nonnull theme;

/**
 *  the currently active and visible viewController instance
 */
@property (nonatomic, weak) JudoPayViewController * _Nullable activeViewController;


/**
 *  designated initializer of JudoKit
 *
 *  @param token                    a string object representing the token
 *  @param secret                   a string object representing the secret
 *  @param jailbrokenDevicesAllowed a boolean indicating whether the sdk should allow access from jailbroken devices
 *
 *  @return a new instance of JudoKit
 */
- (nonnull instancetype)initWithToken:(nonnull NSString *)token
                               secret:(nonnull NSString *)secret
               allowJailbrokenDevices:(BOOL)jailbrokenDevicesAllowed;


/**
 *  convenient initializer of JudoKit. This allows Jailbroken devices to make payments by default
 *
 *  @param token  a string object representing the token
 *  @param secret a string object representing the secret
 *
 *  @return a new instance of JudoKit
 */
- (nonnull instancetype)initWithToken:(nonnull NSString *)token
                               secret:(nonnull NSString *)secret;


/**
 *  This method will invoke the Judo UI on the top UIViewController instance of the Applications window. When the form has been successfully filled, the button will invoke a payment with the judo API and respond in a completion block
 *
 *  @param judoId      The judoID of the merchant to receive the payment
 *  @param amount      The amount and currency of the payment (default is GBP)
 *  @param reference   holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *  @param cardDetails The card details to present in the input fields
 *  @param completion  The completion handler which will respond with a JPResponse object or an NSError
 */
- (void)invokePayment:(nonnull NSString *)judoId
               amount:(nonnull JPAmount *)amount
    consumerReference:(nonnull NSString *)reference
          cardDetails:(nullable JPCardDetails *)cardDetails
           completion:(nonnull void(^)(JPResponse * _Nullable, NSError * _Nullable))completion;


/**
 *  This method will invoke the Judo UI on the top UIViewController instance of the Applications window. When the form has been successfully filled, the button will invoke a pre-auth with the judo API and respond in a completion block
 *  
 *  @param judoId      The judoID of the merchant to receive the pre-auth
 *  @param amount      The amount and currency of the pre-auth (default is GBP)
 *  @param reference   holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *  @param cardDetails The card details to present in the input fields
 *  @param completion  The completion handler which will respond with a JPResponse object or an NSError
 */
- (void)invokePreAuth:(nonnull NSString *)judoId
               amount:(nonnull JPAmount *)amount
    consumerReference:(nonnull NSString *)reference
          cardDetails:(nullable JPCardDetails *)cardDetails
           completion:(nonnull void(^)(JPResponse * _Nullable, NSError * _Nullable))completion;


/**
 *  This method will invoke the Judo UI on the top UIViewController instance of the Applications window. When the form has been successfully filled, the button will invoke a card registration with the judo API and respond in a completion block
 *
 *  @param judoId      The judoID of the merchant to receive the pre-auth
 *  @param amount      The amount and currency of the pre-auth (default is GBP)
 *  @param reference   holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *  @param cardDetails The card details to present in the input fields
 *  @param completion  The completion handler which will respond with a JPResponse object or an NSError
 */
- (void)invokeRegisterCard:(nonnull NSString *)judoId
                    amount:(nonnull JPAmount *)amount
         consumerReference:(nonnull NSString *)reference
               cardDetails:(nullable JPCardDetails *)cardDetails
                completion:(nonnull void(^)(JPResponse * _Nullable, NSError * _Nullable))completion;


/**
 *  This method will invoke the Judo UI on the top UIViewController instance of the Applications window. This method needs the cardDetails object in order to show the known details to the user when entering the CV2. When the form has been successfully filled, the button will invoke a token payment with the judo API and respond in a completion block
 *
 *  @param judoId       The judoID of the merchant to receive the token payment
 *  @param amount       The amount and currency of the payment (default is GBP)
 *  @param reference    holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *  @param cardDetails  The card details to present in the input fields
 *  @param paymentToken The consumer and card token to make a token payment with
 *  @param completion   The completion handler which will respond with a JPResponse object or an NSError
 */
- (void)invokeTokenPayment:(nonnull NSString *)judoId
                    amount:(nonnull JPAmount *)amount
         consumerReference:(nonnull NSString *)reference
               cardDetails:(nonnull JPCardDetails *)cardDetails
              paymentToken:(nonnull JPPaymentToken *)paymentToken
                completion:(nonnull void(^)(JPResponse * _Nullable, NSError * _Nullable))completion;


/**
 *  This method will invoke the Judo UI on the top UIViewController instance of the Applications window. This method needs the cardDetails object in order to show the known details to the user when entering the CV2. When the form has been successfully filled, the button will invoke a token pre-auth with the judo API and respond in a completion block
 *
 *  @param judoId       The judoID of the merchant to receive the token pre-auth
 *  @param amount       The amount and currency of the pre-auth (default is GBP)
 *  @param reference    holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *  @param cardDetails  The card details to present in the input fields
 *  @param paymentToken The consumer and card token to make a token payment with
 *  @param completion   The completion handler which will respond with a JPResponse object or an NSError
 */
- (void)invokeTokenPreAuth:(nonnull NSString *)judoId
                    amount:(nonnull JPAmount *)amount
         consumerReference:(nonnull NSString *)reference
               cardDetails:(nonnull JPCardDetails *)cardDetails
              paymentToken:(nonnull JPPaymentToken *)paymentToken
                completion:(nonnull void(^)(JPResponse * _Nullable, NSError * _Nullable))completion;


/**
 *  This method only creates a JPPayment object for usages in a custom UI. This means the developer needs to set the remaining mandatory fields like a payment method (card, token or PKPayment object for ApplePay) to then make the transaction
 *
 *  @param judoId    The judoID of the merchant to receive the transaction
 *  @param amount    The amount and currency of the payment (default is GBP)
 *  @param reference holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *
 *  @return a JPPayment object
 */
- (nonnull JPPayment *)paymentWithJudoId:(nonnull NSString *)judoId
                                  amount:(nonnull JPAmount *)amount
                               reference:(nonnull JPReference *)reference;


/**
 *  This method only creates a JPPreAuth object for usages in a custom UI. This means the developer needs to set the remaining mandatory fields like a payment method (card, token or PKPayment object for ApplePay) to then make the transaction
 *
 *  @param judoId    The judoID of the merchant to receive the transaction
 *  @param amount    The amount and currency of the pre-auth (default is GBP)
 *  @param reference holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *
 *  @return a JPPreAuth object
 */
- (nonnull JPPreAuth *)preAuthWithJudoId:(nonnull NSString *)judoId
                                  amount:(nonnull JPAmount *)amount
                               reference:(nonnull JPReference *)reference;


/**
 *  This method only creates a JPRegisterCard object for usages in a custom UI. This means the developer needs to set the remaining mandatory fields like a payment method (card, token or PKPayment object for ApplePay) to then make the transaction
 *
 *  @param judoId    The judoID of the merchant to receive the transaction
 *  @param amount    The amount and currency of the pre-auth (default is GBP)
 *  @param reference holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *
 *  @return a JPRegisterCard object
 */
- (nonnull JPRegisterCard *)registerCardWithJudoId:(nonnull NSString *)judoId
                                            amount:(nullable JPAmount *)amount
                                         reference:(nonnull JPReference *)reference;


/**
 *  This method creates a JPCollection object that can be used to collect a previously pre-authorized transaction.
 *
 *  @param receiptId the receipt ID
 *  @param amount    The amount and currency of the collection (default is GBP)
 *
 *  @return a JPCollection object
 */
- (nonnull JPCollection *)collectionWithReceiptId:(nonnull NSString *)receiptId
                                           amount:(nonnull JPAmount *)amount;


/**
 *  This method creates a JPVoid object that can be used to void a previously pre-authorized transaction to free the reserved funds on the users card
 *
 *  @param receiptId the receipt ID
 *  @param amount    The amount and currency of the void (default is GBP)
 *
 *  @return a JPVoid object
 */
- (nonnull JPVoid *)voidWithReceiptId:(nonnull NSString *)receiptId
                               amount:(nonnull JPAmount *)amount;


/**
 *  This method creates a JPRefund object that can be used to refund a previous payment transaction and refunds the given amount back to the users card
 *
 *  @param receiptId the receipt ID
 *  @param amount    The amount and currency of the refund (default is GBP)
 *
 *  @return a JPRefund object
 */
- (nonnull JPRefund *)refundWithReceiptId:(nonnull NSString *)receiptId
                                   amount:(nonnull JPAmount *)amount;


/**
 *  Create a JPReceipt object to query for a given receipt ID or all receipts.
 *
 *  @param receiptId the receipt ID to query for - nil for a list of all receipts
 *
 *  @return a JPReceipt object
 */
- (nonnull JPReceipt *)receipt:(nullable NSString *)receiptId;


/**
 *  a helper method that lists all the transaction for a given class that conforms to JPTransaction (JPPayment, JPPreAuth, JPRegisterCard)
 *
 *  @param type       the Class that conforms to JPTransaction to be queried for its list
 *  @param pagination an optional pagination object for multi-paged requests
 *  @param completion The completion handler which will respond with a JPResponse object or an NSError
 */
- (void)list:(nonnull Class)type
   paginated:(nullable JPPagination *)pagination
  completion:(nonnull void(^)(JPResponse * _Nullable, NSError * _Nullable))completion;


/**
 *  Helper method that creates a Transaction based on the Class that is passed (JPPayment, JPPreAuth or JPRegisterCard)
 *
 *  @param type      the Class that conforms to JPTransaction to be created with this method
 *  @param judoId    The judoID of the merchant to receive the transaction
 *  @param amount    The amount and currency of the transaction (default is GBP)
 *  @param reference holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *
 *  @return a JPTransaction object
 */
- (nonnull JPTransaction *)transactionForTypeClass:(nonnull Class)type
                                            judoId:(nonnull NSString *)judoId
                                            amount:(nonnull JPAmount *)amount
                                         reference:(nonnull JPReference *)reference;


/**
 *  Helper method that creates a Transaction based on the TransactionType that is passed (Payment, PreAuth or RegisterCard)
 *
 *  @param type      the TransactionType to be created with this method
 *  @param judoId    The judoID of the merchant to receive the transaction
 *  @param amount    The amount and currency of the transaction (default is GBP)
 *  @param reference holds consumer and payment reference and a meta data dictionary which can hold any kind of JSON formatted information up to 1024 characters
 *
 *  @return a JPTransaction object
 */
- (nonnull JPTransaction *)transactionForType:(TransactionType)type
                                       judoId:(nonnull NSString *)judoId
                                       amount:(nonnull JPAmount *)amount
                                    reference:(nonnull JPReference *)reference;

@end
