using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;
using System.Web.Http;
using MSP1.Models;
namespace MSP1.Controllers
{
    public class MSPController : ApiController
    {
        [HttpGet]
        public string GetAllEmployees()
        {
            //Return list of all employees  
            return "Hello Happy to see me";
        }
        [HttpPost]
        public async Task<string> HandlePostRequest(ForeignData value)
        {
            if (value.operation != null && value.operation.CompareTo("login") == 0)
            {
                HttpClient client = new HttpClient();
                String url = String.Format("https://graph.microsoft.com/v1.0/users?$filter=userPrincipalName eq '{0}@microsoft.com'", value.EmpAlias);
                //String url = String.Format("http://who/is/{0}", value.EmpAlias);
                client.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", "eyJ0eXAiOiJKV1QiLCJub25jZSI6IkFRQUJBQUFBQUFCbmZpRy1tQTZOVGFlN0NkV1c3UWZkVHc0RkZnWXVmY0R4Uzl2ZXZvbDVoTllHOGF2YUJ1X3BoMzRsd1c1WmdNVE5hd1N3WWpKbGJYY3JCMWZLTDJvYnZJTWIyQ0ZYUmc0ekNrSmYxQXVSZXlBQSIsImFsZyI6IlJTMjU2IiwieDV0IjoiVldWSWMxV0QxVGtzYmIzMDFzYXNNNWtPcTVRIiwia2lkIjoiVldWSWMxV0QxVGtzYmIzMDFzYXNNNWtPcTVRIn0.eyJhdWQiOiJodHRwczovL2dyYXBoLm1pY3Jvc29mdC5jb20iLCJpc3MiOiJodHRwczovL3N0cy53aW5kb3dzLm5ldC83MmY5ODhiZi04NmYxLTQxYWYtOTFhYi0yZDdjZDAxMWRiNDcvIiwiaWF0IjoxNTAxMDgyNzY3LCJuYmYiOjE1MDEwODI3NjcsImV4cCI6MTUwMTA4NjY2NywiYWNyIjoiMSIsImFpbyI6IkFTUUEyLzhEQUFBQURLeHk2YkJja2IxZXE4dDhibis3QTByaHJ6M3hTdUhuc2VWQTA1Z3cvbG89IiwiYW1yIjpbInB3ZCIsIm1mYSJdLCJhcHBfZGlzcGxheW5hbWUiOiJHcmFwaCBleHBsb3JlciIsImFwcGlkIjoiZGU4YmM4YjUtZDlmOS00OGIxLWE4YWQtYjc0OGRhNzI1MDY0IiwiYXBwaWRhY3IiOiIwIiwiZGV2aWNlaWQiOiI5YjBkM2ZlMy1mNjdlLTQ4NDQtODQ3My03MjYwYTgxZjRjNDQiLCJmYW1pbHlfbmFtZSI6IlNpbmdoIiwiZ2l2ZW5fbmFtZSI6IlByYXZlZW4iLCJpbl9jb3JwIjoidHJ1ZSIsImlwYWRkciI6IjE2Ny4yMjAuMjM4LjE1NCIsIm5hbWUiOiJQcmF2ZWVuIFNpbmdoIiwib2lkIjoiMzhlZGZlODktNjMxOC00Mzg1LTlkZTgtYjk2ODU1ODc1ZTkwIiwib25wcmVtX3NpZCI6IlMtMS01LTIxLTIxNDY3NzMwODUtOTAzMzYzMjg1LTcxOTM0NDcwNy0yMTE5Nzk1IiwicGxhdGYiOiIzIiwicHVpZCI6IjEwMDMwMDAwOTkyOTg5NUYiLCJzY3AiOiJDYWxlbmRhcnMuUmVhZFdyaXRlIENvbnRhY3RzLlJlYWRXcml0ZSBEZXZpY2VNYW5hZ2VtZW50QXBwcy5SZWFkV3JpdGUuQWxsIERldmljZU1hbmFnZW1lbnRDb25maWd1cmF0aW9uLlJlYWRXcml0ZS5BbGwgRGV2aWNlTWFuYWdlbWVudE1hbmFnZWREZXZpY2VzLlByaXZpbGVnZWRPcGVyYXRpb25zLkFsbCBEZXZpY2VNYW5hZ2VtZW50TWFuYWdlZERldmljZXMuUmVhZFdyaXRlLkFsbCBEZXZpY2VNYW5hZ2VtZW50UkJBQy5SZWFkV3JpdGUuQWxsIERldmljZU1hbmFnZW1lbnRTZXJ2aWNlQ29uZmlndXJhdGlvbi5SZWFkV3JpdGUuQWxsIERpcmVjdG9yeS5BY2Nlc3NBc1VzZXIuQWxsIERpcmVjdG9yeS5SZWFkLkFsbCBEaXJlY3RvcnkuUmVhZFdyaXRlLkFsbCBGaWxlcy5SZWFkV3JpdGUuQWxsIEdyb3VwLlJlYWRXcml0ZS5BbGwgSWRlbnRpdHlSaXNrRXZlbnQuUmVhZC5BbGwgTWFpbC5SZWFkV3JpdGUgTm90ZXMuUmVhZFdyaXRlLkFsbCBQZW9wbGUuUmVhZCBTaXRlcy5SZWFkV3JpdGUuQWxsIFRhc2tzLlJlYWRXcml0ZSBVc2VyLlJlYWRCYXNpYy5BbGwgVXNlci5SZWFkV3JpdGUgVXNlci5SZWFkV3JpdGUuQWxsIiwic2lnbmluX3N0YXRlIjpbImR2Y19tbmdkIiwiZHZjX2NtcCIsImR2Y19kbWpkIiwia21zaSJdLCJzdWIiOiIyZ01wYVU2VlY1ZVVVcDR5VmpxMEFlY1k3RUxnZFRuTDhtS3BBb2YzVkdnIiwidGlkIjoiNzJmOTg4YmYtODZmMS00MWFmLTkxYWItMmQ3Y2QwMTFkYjQ3IiwidW5pcXVlX25hbWUiOiJwcmFzaW5naEBtaWNyb3NvZnQuY29tIiwidXBuIjoicHJhc2luZ2hAbWljcm9zb2Z0LmNvbSIsInV0aSI6Ikh4ZWVuNE9kNjAtUkpYcjlWek1HQUEiLCJ2ZXIiOiIxLjAifQ.enuxOH_rY-0SJBS7btLVmEGj0jQdi9jQfMgs-K2tITYMYDTLCdixJSV9iIudYfh_CXEOUC97AlchwBoNXexQaQrZTCP3v8mZhJEbP92F6RbazcfAd04Dy9WO8aEVco9ZBpCDYkMxj-Uo1YUDOiRsa3BvhKYWfItSoLBLYKGxkZBaNZzs3Vvk657LlYGDO_ZmoAa_FLM-4m5KA1ch92shHq7pg6lEiuFT2EET7pe81R57Ug0g1vUq2CWFcqQdBwBFHJSo8P9l3eUt-Xh3KnHG74sU2HPJxDXmP83tjikSCybuTXK_a_ll3m7aGyvENoT8RJQGvle6EW-rbCi2LSqVAg");
                var responseString = await client.GetStringAsync(url);
                // parse json and send name and location success
            }
            if (value.operation != null && value.operation.CompareTo("entry") == 0)
            {

            }
            if (value.operation != null && value.operation.CompareTo("entry") == 0)
            {

            }
            return value.EmpAlias;
            //write insert logic  
        }
    }
}
