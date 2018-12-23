using System;
using System.Web.Mvc;
using URlShortening;

namespace WebUrl.Controllers
{
	public class listItem
	{
		string text;
		string value;
	}
	public class UrlController : Controller
	{
		// GET: Url
		[Route("")]
		public ActionResult Index(string shorturl)
		{
			ViewBag.resultTitle = "Result";
			string rawUrl = HttpContext.Request.RawUrl;

			if (string.IsNullOrEmpty(shorturl))
			{
				if (!string.IsNullOrEmpty(rawUrl) && rawUrl.Contains(@"?") == true)
				{
					DatabaseHandler dbHandler = new DatabaseHandler();
					string suburl = rawUrl.Substring(2);
					string longurl = dbHandler.getData(suburl);
					if (!string.IsNullOrEmpty(longurl))
					{
						return Redirect(longurl);
					}
					else
					{
						return View();
					}


				}
				return View();
			}
			else
			{
				//return Content(shorturl);
				return View();
			}
		}

		[HttpPost]
		public ActionResult Index(FormCollection collection)
		{
			string longurl = collection["longurl"];
			string shorturl = collection["shorturl"];
			string clinet = collection["client"];
			string user = collection["user"];

			if (!string.IsNullOrEmpty(longurl))
			{
				DatabaseHandler dbHandler = new DatabaseHandler();
				Hash hash = new Hash();
				string inputUrl = longurl;
				string origurl = inputUrl;
				string hashkey;
				int ret = int.MinValue;
				Random rand = new Random();
				do
				{
					hashkey = hash.getHashSha256(inputUrl);
					ret = dbHandler.SetData(hashkey, origurl);
					inputUrl += rand.Next().ToString();

				} while (ret != 0);
				//http://adobe.zcvfit.com/?RaM5
				//string baseurl = "http://zcv.azurewebsites.net?";
				string baseurl = ".zcvfit.com/?";
				ViewBag.fullurl = "http://" + clinet + baseurl + hashkey;
				ViewBag.resultTitle = "Short Url";
				return View();
			}
			else if (!string.IsNullOrEmpty(shorturl))
			{
				DatabaseHandler dbHandler = new DatabaseHandler();
				string suburl = shorturl.Substring(shorturl.Length - 4);
				string lurl = dbHandler.getData(suburl);
				ViewBag.fullurl = lurl;
				ViewBag.resultTitle = "Long Url";
				return View();

			}

			else
			{
				return Content(shorturl);
				//return View();
			}
		}
		// GET: Url/Details/5


	}
}
