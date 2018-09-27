#ifndef ___MYSTRUCT_H__
#define ___MYSTRUCT_H__

struct SHShare
{
	//ordwth 接口字段格式初始化，理应 ,为在后续使用中修改，没有设置静态;
	std::string date;			//日期年月日
	std::string time;		//时间时分秒
	std::string reff;			//内部会员订单号
	std::string account;		//股票账号
	std::string stock;			// 证券代码
	std::string bs;				//买卖;‘B’或者‘b’代表买入，‘S’或者‘s’代表卖出。
	std::string price;			//价格
	std::string qty;			// 成交原始数量，
	std::string status;			//R表示未发送，P表示已发送
	std::string owflag;			//订单类型标志 撤单WTH
	std::string ordrec;			//撤单号 = rec_num
	std::string frimid;			//B股的发行结算代码，对A股无意义；
	std::string brandchid;		//营业部代码
	std::string checkord;		//binary 校验码 实际上没设置这个本来是二进制的字段，使用时在OrdwthStruct和CancelOrderStruct里再单独写入string

	std::string rec_num;		//订单编号；多个验股测试样例时，检查股份需要递增
	std::string nullstr;		//用于重载string+ 时对加操作要求有一项为string类；
	//	int tempOrderNum;			//当前订单数量
SHShare();		//构造函数；
	~SHShare();		//析构函数；
	std::string GetSQlInsertSentence();		//获取要执行的插入语句

	std::string GetSQLCancelSentence();		//获取要执行的撤销语句

	std::string GetQueryOrdwthCancel()		//查询ordwth中的撤单
	{
		//插入撤单;将owflag 和 orderrec修改
		int tempRecNum = 0;
		std::string CancelOwflag = ("WTH");
		std::string CancelOrdrec = rec_num;

		//查询ordwth中的撤单，以ordrec、owflag为条件；
		std::string strQueryOrdwthCancel = "select * from [Ashare_OIW].[dbo].[ashare_ordwth] where owflag='";
		strQueryOrdwthCancel += CancelOwflag;
		strQueryOrdwthCancel += "' and ordrec =";
		strQueryOrdwthCancel += CancelOrdrec;
		strQueryOrdwthCancel += ";";
		return strQueryOrdwthCancel;
	}

	std::string GetQueryOrdwth2Cancel()
	{
		//插入撤单;将owflag 和 orderrec修改
		std::string CancelOwflag = ("WTH");
		std::string CancelOrdrec = rec_num;

		//查询ordwth2， 以reff 、owflag为条件,不以rec_num是因为这个字段无法预测（由tgw控制产生）。
		std::string strQueryOrdwth2Cancel = "select * from [Ashare_OIW].[dbo].[ashare_ordwth2] where owflag='";
		strQueryOrdwth2Cancel += CancelOwflag;
		strQueryOrdwth2Cancel += "' and ordrec ='";
		strQueryOrdwth2Cancel += CancelOrdrec;
		strQueryOrdwth2Cancel += "';";
		return strQueryOrdwth2Cancel;
	}
};
struct Compound
{
    char c;
    double d;
};

#endif // __MYSTRUCT_H__
