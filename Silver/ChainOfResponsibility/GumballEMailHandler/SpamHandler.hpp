#ifndef	_HFDP_CPP_CHAIN_OF_RESPONSIBILITY_SPAM_HANDLER_HPP_
#define _HFDP_CPP_CHAIN_OF_RESPONSIBILITY_SPAM_HANDLER_HPP_

#include "Hum_Log_Manager.h"
#include "Hum_Trace.h"

namespace HeadFirstDesignPatterns {
  namespace ChainOfResponsibility {
    namespace GumballEMailHandler {

      class SpamHandler : public Handler {
      public:
        explicit SpamHandler( const Handler* successor = 0 ) :
          Handler( successor )
        {
          HUM_TRACE(ACE_TEXT("SpamHandler::SpamHandler"));
        }
        void handleRequest( std::string request ) const
        {
          HUM_TRACE(ACE_TEXT("SpamHandler::handleRequest"));
          std::transform( request.begin(), request.end(), request.begin(),
                          tolower );

          if( canHandleRequest( request ) == true ) {
            Handler::canHandleRequest( request );
          } else {
            Handler::handleRequest( request );
          }
        }
        bool canHandleRequest( const std::string& request ) const
        {
          HUM_TRACE(ACE_TEXT("SpamHandler::canHandleRequest"));
          bool value = false;

          if( std::string::npos != request.find( "bread" ) ) {
            value = true;
          } else if( std::string::npos != request.find( "buzzin" ) ) {
            value = true;
          } else if( std::string::npos != request.find( "cuzzin" ) ) {
            value = true;
          } else if( std::string::npos != request.find( "eyeball" ) ) {
            value = true;
          }
          return value;
        }
        void print() const
        {
          HUM_TRACE(ACE_TEXT("SpamHandler::print"));
          std::cout << std::endl << "Spam mail, send to shredder:";
          Handler::print();
        }
      };

    } // namespace GumballEMailHandler
  } // namespace ChainOfResponsibility
} // namespace HeadFirstDesignPatterns

#endif
