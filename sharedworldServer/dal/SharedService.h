#ifndef _SHARED_SERVICE_H_
#define _SHARED_SERVICE_H_

#include "ISharedService.h"
#include "../JOutStream.h"
class SharedService : public ISharedService
{
public:
	// 用户登录
	int UserLogin(const string& user, const string& pass, list<string>& activeUsers);
	// 注册
	int UserRegister(const Account& account);
	// 上传文件
	int UpLoadFile(string fileName, string userName);
	// 请求资源路径名
	int RequestResource(string userName, JOutStream& jos); 

	// 请求资源并发送资源文件
	int RequestAndSendResource(string userName, string filepath, JOutStream& jos);

	//退出
	int LogOut(string account, JOutStream& jos, int len);
	// 修改密码
	int ChangePassword(Account& account, const string& newPass);
	// 查询某日报表
	int QueryDayBill(list<TransDetail>& result, int page, const string& date);
	// 根据日期查询明细
	int QueryHistoryBill(list<TransDetail>& result, int page, const string& begin, const string& end);
	// 根据帐号查询明细
	int QueryAccountHistoryBill(list<TransDetail>& result, int page, const string& accountId, const string& begin, const string& end);
};

#endif /* _SHARED_SERVICE_H_ */
