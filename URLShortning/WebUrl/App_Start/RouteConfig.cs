using System.Web.Mvc;
using System.Web.Routing;
using WebUrl.Controllers;

namespace WebUrl
{
	public class RouteConfig
	{
		public static void RegisterRoutes(RouteCollection routes)
		{
			routes.IgnoreRoute("{resource}.axd/{*pathInfo}");
			routes.Add(new SubdomainRoute());

			routes.MapRoute(
				name: "Default",
				url: "{controller}/{action}/{shorturl}",
				defaults: new { controller = "url", action = "Index", shorturl = UrlParameter.Optional }
			);
		}
	}
}
