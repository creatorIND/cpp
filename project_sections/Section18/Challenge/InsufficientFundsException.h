#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_H_
#define _INSUFFICIENT_FUNDS_EXCEPTION_H_

class InsufficientFundsException: public std::exception
{
public:
	InsufficientFundsException() noexcept = default;
	virtual const char *what() const noexcept {
		return "Account Not Debited: Insufficient Funds";
	}
	~InsufficientFundsException() = default;

};

#endif // _INSUFFICIENT_FUNDS_EXCEPTION_H_
