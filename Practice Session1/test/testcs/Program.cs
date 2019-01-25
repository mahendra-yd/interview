using Newtonsoft.Json;
using System;

namespace testcs
{

    class Product
    {
        public string Name { get; set; }
        public DateTime Expiry { get; set; }
        public Decimal Price { get; set; }
        public string[] Sizes { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Product product = new Product();
            product.Name = "Apple";
            product.Expiry = new DateTime(2008, 12, 28);
            product.Price = 3.99M;
            product.Sizes = new string[] { "Small", "Medium", "Large" };

            string json = JsonConvert.SerializeObject(product);

            Console.WriteLine("Hello World!");
        }
    }
}
