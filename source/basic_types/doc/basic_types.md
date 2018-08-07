看一看下面这段代码，谈一下你的感受：
class IProxyHostEventCallback
{
public:
  virtual VOID OnNetworkResponse(DWORD dwGameId, BOOL bSuccess) = 0;
  virtual VOID OnServerInfo(UINT nGameid, SERVER_INFO &info) = 0;
  virtual VOID OnRefreshStop(DWORD nGameId) = 0;
  virtual VOID OnRefreshFinish(int nGameId, ...) = 0;
  virtual void OnVpnRefreshFinish(int nGameId, ...) = 0;
  virtual void OnPptpRefreshFinish(int nGameId, bool bSuccess, ...) = 0;
  virtual void OnServerInfoRefreshFinishNotify(UINT nGameid) = 0;
  virtual void OnRefreshNodeError(DWORD dwError) = 0;
};

如果单独看每个方法的声明，这样的写法并没有什么错误，可是一旦把这些方法凑在一起，由于各种基础数据类型的写法不统一，难免会给人一种不专业的、东拼西凑的感觉。