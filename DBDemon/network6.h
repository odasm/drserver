
#define GM_TOOL_VERSION 4987457
const int MAX_NAME = 21;
extern int	CheckGameMakeTool(char *id, char ip[40]);	// 020830 YGI

//011030 lsw >
#define CMD_RARE_ITEM_MAKE_LOG		9008
typedef struct rare_item_make_log
{
	int map;
	//date; �ڵ� ���
	char maker[20];
	
	int itemno;//������ ��ü �ѹ�
	
	int today_count;//���� ��� �������
	
	int grade;

	int mutanttype1;
	int mutanttype2;
	int mutanttype3;

	int addeditem1;
	int addeditem1limit;
	int addeditem2;
	int addeditem2limit;

	int resultlimit;
	int resultnowdur;//
	int resultmaxdur;//
	
	int why;
	int why2;

	int resource1limit;//����
	int resource2limit;
	int resource3limit;
	int resource4limit;
	int resource5limit;
	int resource6limit;

}t_rare_item_make_log;

#define CMD_CONFORM_SADONIX		9009
typedef struct CONFORMSADONIX
{
	int		cn;
	char	name[20];
	int		kind;
	ItemAttr item;
	int		x;
	int		y;
}t_ConformSadonix,*LPCONFORMSADONIX;

#define CMD_SADONIX_COUNT_UPDATE		9010//020505 lsw
typedef struct SADONIXCOUNTUPDATE
{
	short nSadTime;
}t_SadonixCountUpdate,*LPSADONIXCOUNTUPDATE;

/*
typedef struct SADONIXCONTROL
{
	int No;
	int Day[7];
}SadonixControl,*LPSadonixControl;

extern SadonixControl	sadonixcontrol[24];//24�ð� �̴ϱ�
*/

//acer7
extern BOOL DumpException(LPEXCEPTION_POINTERS lpExcep,char* szOutMsg, void *pData = NULL, int nSize = 0);
extern int IsBlockedId(const char *cheak_name);
extern void ProcessEnd(const int iDestroyType);
extern int IsSecretKeyCodeOk(const char *log_id,const char *szSecretKeyCode);


typedef struct ITEMRAREMAIN
{
	DWORD	grade			: 4;//���
	DWORD	soksung1		: 8;//�Ӽ�1
	DWORD	soksung2		: 8;//�Ӽ�2 ��Ƽ �Ӽ�
	DWORD	soksung3		: 8;//�ð����
	DWORD	iHighLevel		: 3;//�÷��� Ÿ�� ���� �ִٸ� IsDynamicRare-->�� �ݵ�� 0 �̾�� �Ѵ�
	DWORD	IsDynamicRare	: 1;//1 �̸� ��� ������ 0 �̸� ���� ������
}RareMain, *LPRareMain;

typedef struct EVENTITEM
{
	int iIndex;
	int iEvevntType;
	int iItemNo;
	int iRareKind1;
	int iRareKind2;
	int iRareKind3;
	int iGrade;
	int isDynamic;
	int iHighRare;
}t_EventItem,*LPEVENTITEM;
const int MAX_EVENT_ITEM = 400;

extern int LoadEventRareItem();

#define CMD_COMFORM_RESET_ABILILTY				9020//020820 lsw
typedef struct COMFORMRESETABILILTY
{
	int cn;
	char szName[21];
	int iIsAble;//020821-1 lsw
}t_ComformResetAbililty,*LPCOMFORMRESETABILILTY;


//<soto-030514 ����.
typedef struct SEARCHPACKETCLIENT
{
	char	szKeyWord[21];	//Ű���� �˻��� ��
	char	szMerchant[21]; //�����̸� �˻��� ��
	int		nPeriod;		//��� �Ⱓ ����.// 0:1��, 1:3��,  2:������.
	int		iIndex;
	int		iKey;
}t_SearchPacketClient,*lpSEARCHPACKETCLIENT;

//�����ڿ� �˻� ����ü
#define CMD_MERCHANT_BUY_ITEM_SEARCH_SERVER			16002//020815 lsw
typedef struct SEARCHPACKETSERVER
{
	int iCn;
	char szName[21];
	t_SearchPacketClient	ClientMsg;
}t_SearchPacketServer,*lpSEARCHPACKETSERVER;
//>soto-030514 ����.


typedef struct SEARCHRESULT
{
	int			iIndex;
	char		szSellerName[21];
	char		szBuyerName[21];
	int			iSellValue;//�Ǹűݾ��� 20���� �ѱ��� �ʽ��ϴ�.
	int			iIsEnd;
	int			iSellerTake;
	int			iBuyerTake;
	ItemAttr	m_ResultItem;
}t_SearchResult,*lpSEARCHRESULT;

#define CMD_MERCHANT_BUY_ITEM_SEARCH_RESULT			16001//020815 lsw
#define CMD_MERCHANT_SELL_LIST_REQUEST_RESULT		16004
#define CMD_MERCHANT_RESULT_LIST_REQUEST			16030
#define CMD_MERCHANT_RESULT_LIST_REQUEST_RESULT		16031
const int MAX_SEARCH_RESULT_LIST = 24;
typedef struct SEARCHRESULTLIST
{
	int	 iCn;
	char szName[21];
	int iKey;
	SEARCHRESULT ResultList[MAX_SEARCH_RESULT_LIST];
}t_SearchResultList,*lpSEARCHRESULTLIST;
//
//�����ڿ� ������ ������ �ϰڴٴ� ��Ŷ
#define CMD_MERCHANT_ITEM_BUY					16005//Ŭ���̾�Ʈ ���� �ް� 
#define CMD_MERCHANT_ITEM_BUY_RESULT			16006
#define CMD_MERCHANT_ITEM_BUY_COMFORM			16007//���� ���
#define CMD_MERCHANT_ITEM_BUY_COMFORM_RESULT	16008//���� ���
typedef struct MERCHANT_ITEM_BUY
{
	int			iIndex;//������ �������� �ε��� ��
	int			iCn;//Ŀ�ؼ� ��
	char		szSellerName[21];//�Ǹ��� �̸�
	char		szBuyerName[21];//������ �̸�
	DWORD		dwSellValue;//�Ǹűݾ��� 20���� �ѱ��� �ʽ��ϴ�.
	ItemAttr	SellItem;
	int			iKey;
}t_MerchantItemBuy,*lpMERCHANTITEMBUY;

//
//�Ǹ��ڿ� ����ü
#define CMD_MERCHANT_SELL_ITEM_INFO_REQUEST		16003
typedef struct SELLERITEMREQUEST
{
	int iCn;
	int iIndex;
	int iKey;
	char szName[21];//�ڽ��� �̸��� ������ �������� �˻� �մϴ�.
}t_SellerItemRequest,*lpSELLERITEMREQUEST;

#define CMD_MERCHANT_SELL_ITEM_REGISTER					16009//�Ǹž������� ��� �մϴ�.
#define CMD_MERCHANT_SELL_ITEM_REGISTER_RESULT			16010//�Ǹž������� ��� �մϴ�.
#define CMD_MERCHANT_SELL_ITEM_REGISTER_COMFORM			16011//�Ǹž������� ��� �մϴ�.(��� �������� ��û �մϴ�.
#define CMD_MERCHANT_SELL_ITEM_REGISTER_COMFORM_RESULT	16012//�Ǹž������� ��� �մϴ�.(��� ���� ��� �ϰ� ��� �Ѥ�;.. ����������..
typedef struct SELLERITEMREGISTER
{
	int			iCn;
	char		szName[21];
	int			iFKRareType;
	int			iFKLevel;
	int			iFKTacticType;
	int			iFKWearType;
	POS			pos;
	DWORD		dwSellValue;
	ItemAttr	SellItem;
	int			iKey;
}t_SellerItemRegister,*lpSELLERITEMREGISTER;

#define CMD_MERCHANT_SELL_ITEM_DELETE					16020//�ǸŸ� ����մϴ�.//Ŭ���̾�Ʈ��
#define CMD_MERCHANT_SELL_ITEM_DELETE_RESULT			16021//�ǸŸ� ����մϴ�.
#define CMD_MERCHANT_SELL_ITEM_DELETE_COMFORM			16022//�ǸŸ� ����մϴ�.//��� ��û
#define CMD_MERCHANT_SELL_ITEM_DELETE_COMFORM_RESULT	16023//�ǸŸ� ����մϴ�.//��� �������� ����� Ŭ���̾�Ʈ���� ����
#define CMD_MERCHANT_RECORD_DEL_CANCLE					16024	// BBD 040226 �Ǹ� ��ҷ� ���ڵ� ���� ��û.
#define CMD_MERCHANT_RECORD_DEL_CANCLE_RESULT			16025	// BBD 040226 �Ǹ� ��ҷ� ���ڵ� ���� ���. ���� ���ġ ����
#define CMD_MERCHANT_RECORD_DEL_COMPLETE				16026	// BBD 040226 �ŷ� ����� ���ڵ� ���� ��û.
#define CMD_MERCHANT_RECORD_DEL_COMPLETE_RESULT			16027	// BBD 040226 �ŷ� ����� ���ڵ� ���� ���. ���� ���ġ ����

typedef struct SELLERITEMDELETE
{
	int			iIndex;//�ǸŹ�ǰ�� �ε���
	int			iCn;
	char		szSellerName[21];
	char		szName[21];
	DWORD		dwSellValue;
	ItemAttr	SellItem;
	int			iKey;
}t_SellerItemDelete,*lpSELLERITEMDELETE;


#define CMD_MERCHANT_RESULT_TAKE						16032
#define CMD_MERCHANT_RESULT_TAKE_RESULT					16033
#define CMD_MERCHANT_RESULT_TAKE_COMFORM				16034
#define CMD_MERCHANT_RESULT_TAKE_COMFORM_RESULT			16035

#define	CMD_MERCHANT_BACKUP_LIST_REQUEST				16036	// BBD 040303
#define CMD_MERCHANT_BACKUP_LIST_RESPONSE				16037	// BBD 040303
#define	CMD_MERCHANT_BACKUP_TAKE_REQUEST				16038	// BBD 040303
#define	CMD_MERCHANT_BACKUP_TAKE_RESPONSE				16039	// BBD 040303

#define CMD_EVENTRAREITEM_REQ							16300	// BBD 040308
#define CMD_EVENTRAREITEM_RES							16301	// BBD 040308

typedef struct MERCHANTRESULTTAKE
{
	int			iIndex;//�ǸŹ�ǰ�� �ε���
	int			iCn;
	char		szMyName[21];
	char		szSellerName[21];
	char		szBuyerName[21];
	DWORD		dwSellValue;
	ItemAttr	SellItem;
	int			iSellerTake;
	int			iBuyerTake;
	int			iKey;
}t_MerchantResultTake,*lpMERCHANTRESULTTAKE;

#define CMD_MERCHANT_DIRECT_EXCHANGE_LIST_REQUSET					16090
#define CMD_MERCHANT_DIRECT_EXCHANGE_LIST_REQUSET_RESULT			16091
#define CMD_MERCHANT_EXCHANGE_LIST_REQUSET							16100
#define CMD_MERCHANT_EXCHANGE_LIST_REQUSET_RESULT					16101
typedef struct MERCHANTEXCHANGEREQUEST
{
	int			iIndex;//0���� �������� �ϰ�
	int			iCn;
	char		szSellerName[21];
	char		szMyName[21];
	int			iKey;//�ε��� ���ΰ� �Ʒ��ΰ�.
}t_MerchantExchangeRequest,*lpMERCHANTEXCHANGEREQUEST;

enum eHighLv
{
	H_LV_NO_HIGH_ITEM = 0,
	H_LV_HIGH_ITEM = 1,
	H_LV_LEGEND_ITEM = 2,
};

const int CMD_SELECTED_CHAR_RESULT_CLIENT_BOTH_DB_DEMON	= 16103;
typedef struct SELECTEDCHARRESULT
{
	int			iKey;
	char		szName[21];
	int			iLv;
}t_SelectedCharResult,*LPSELECTEDCHARRESULT;

// Mail System //////////////////////////////////////////////////////////////////////////////
const int MAX_MAIL_PAGE	= 12;
const int MAX_MAIL_PAGE_COUNT	= 5;//�ִ� ��������
const int MAX_MAIL_RECEIVER = 5;
const int MAX_MAIL_BODY_LEN = 1000;

typedef struct MAILDATA
{
	int iIndex;

	int iType;
	bool bIsRead;
	
	char szSender[20];
	char szReceiver[20];
	
	char szTitle[60];
	TIMESTAMP_STRUCT	date;
	int	iBodyIndex;
}t_MailDdata, *LPMAILDATA;

typedef struct MAILBODY
{
	int iIndex;
	char szBody[MAX_MAIL_BODY_LEN];
}t_MailBody, *LPMAILBODY;

const int CMD_MAIL_REQ_BODY		= 16102;//�ش� ������ �ٵ�
typedef struct REQESTMAILBODY
{
//	int iWantMailType;
	int iMailIndex;
	char szName[MAX_NAME];
}t_ReqestMailBody,*LPREQESTMAILBODY;

const int CMD_MAIL_REQ_BODY_RESULT		= 16113;//�ش� ������ �ٵ�
typedef struct REQESTMAILBODYRESULT
{
//	int iWantMailType;
	int iMailIndex;
	int iType;
	char szSender[MAX_NAME];
	char szReceiver[MAX_NAME];
	char szTitle[MAX_NAME];
	TIMESTAMP_STRUCT	date;
	char szBody[MAX_MAIL_BODY_LEN];
}t_ReqestMailBodyResult,*LPREQESTMAILBODYRESULT;

const int CMD_MAIL_REQUEST_LIST = 16114;//�������� �з��� ���� ����Ʈ.
typedef struct REQESTMAILLIST
{
	int iWantMailType;
	int iPageIndex;
	char szName[MAX_NAME];
}t_ReqestMailList,*LPREQESTMAILLIST;

#define CMD_SEND_MAIL_GUILD					10355
#define CMD_REP_RECV_GUILD_MAIL_TITLE		10358

#define CMD_REQ_RECV_MAIL_BODY_GUILD		10359	// ��� ���� Ȯ��
#define CMD_UPDATE_GUILD_MAIL_ID			10360
#define CMD_RECV_MAIL_DELETE_GUILD			10361

const int CMD_MAIL_SEND	=10142;	// ���� ������

typedef struct MAILSEND
{
	int iType;
	char szTarget[MAX_NAME*MAX_MAIL_RECEIVER];//5��
	char szSender[MAX_NAME];
	char szTitle[60];
	char szBody[MAX_MAIL_BODY_LEN];
}t_MailSend,*LPMAILSEND;

const int CMD_MAIL_LIST_FROM_DBDEMON = 16100;
typedef struct MAILLISTRESULT
{
	char szName[MAX_NAME];
	int iWantViewType;
	int iWantViewPage;
	MAILDATA MailData[MAX_MAIL_PAGE];
}t_MailListResult,*LPMAILLISTRESULT;

const int CMD_MAIL_DELETE	=10143;	// ���� ����
const int CMD_MAIL_REPAIR	=10145;	// ���� ����
typedef struct MAILDELETE
{
	int cn;
	char szName[MAX_NAME];
	int aiMailIndex[MAX_MAIL_PAGE];
}t_MailDelete,*LPMAILDELETE;

#define CMD_REQ_RECV_MAIL_BODY				10144	// ���� ���� ��û

#define CMD_REP_RECV_MAIL_TITLE				10145
#define CMD_REP_RECV_MAIL_BODY				10146
#define	CMD_RECV_MAIL_DELETE				10147

const int CMD_MAIL_ALERT = 16400;//���� ��

typedef struct HWOARANG_PACKET
{
	union			
	{
		char	data[MAX_PACKET_SIZE];
		t_SelectedCharResult	SelectedCharResult;
	
		t_ReqestMailList			ReqestMailList;
		t_MailListResult			MailListResult;
		t_MailSend					MailSend;
		t_MailDelete				MailDelete;
		t_ReqestMailBody			ReqestMailBody;
		t_ReqestMailBodyResult		ReqestMailBodyResult;
	}rang;
}t_Hwoarang;