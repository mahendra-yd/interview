using System.Collections.Generic;
using System.Web.Http;

namespace SampleRestServiceWeb.Controllers
{
	public class RestController : ApiController
	{
		// GET: api/Rest
		public IEnumerable<string> Get()
		{
			Models.MessageSender.sendMessage();
			return new string[] { "value1", "value2" };

		}

		// GET: api/Rest/5
		public string Get(int id)
		{
			return "value";
		}

		// POST: api/Rest
		public void Post([FromBody]string value)
		{
		}

		// PUT: api/Rest/5
		public void Put(int id, [FromBody]string value)
		{
		}

		// DELETE: api/Rest/5
		public void Delete(int id)
		{
		}
	}
}
