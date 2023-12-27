#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException: public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
	virtual const char *what() const noexcept {
		return "Account not created: Illegal balance entered";
	}
    ~IllegalBalanceException() = default;
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
