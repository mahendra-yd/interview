using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MSP
{
    public class ProductController : System.Web.Http.ApiController
    {
        //[HttpGet]
        public List<Product> GetProductList()
        {
            List<Product> productLst = new List<Product>{
                new Product{ProductID="P01",ProductName="Pen",Quantity=10,Price=12},
                new Product{ProductID="P02",ProductName="Copy",Quantity=12,Price=20},
                new Product{ProductID="P03",ProductName="Pencil",Quantity=15,Price=22},
                new Product{ProductID="P04",ProductName="Eraser",Quantity=20,Price=27}
                                         };
            return productLst;
        }
        //// GET api/<controller>
        //public IEnumerable<string> Get()
        //{
        //    return new string[] { "value1", "value2" };
        //}

        //// GET api/<controller>/5
        //public string Get(int id)
        //{
        //    return "value";
        //}

        //// POST api/<controller>
        //public void Post([FromBody]string value)
        //{
        //}

        //// PUT api/<controller>/5
        //public void Put(int id, [FromBody]string value)
        //{
        //}

        //// DELETE api/<controller>/5
        //public void Delete(int id)
        //{
        //}
    }
}
