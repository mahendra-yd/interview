using System.Web.Mvc;

namespace WebUrl.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index(string shorturl = "")
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(string longurl, string shorturl, string user)
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}