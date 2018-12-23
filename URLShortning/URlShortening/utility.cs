using System;
using System.Data.SqlClient;
using System.Security.Cryptography;
using System.Text;
namespace URlShortening
{
    public class Hash
    {
        byte[] hash;
        UInt64 a, b, c, d;
        public string getHashSha256(string text)
        {
            string set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";
            byte[] bytes = Encoding.Unicode.GetBytes(text);
            SHA256Managed hashstring = new SHA256Managed();
            hash = hashstring.ComputeHash(bytes);

            a = BitConverter.ToUInt64(hash, 0);
            b = BitConverter.ToUInt64(hash, 8);
            c = BitConverter.ToUInt64(hash, 16);
            d = BitConverter.ToUInt64(hash, 24);

            StringBuilder sb = new StringBuilder();
            sb.Append(set[(int)(a % 64)]);
            sb.Append(set[(int)(b % 64)]);
            sb.Append(set[(int)(c % 64)]);
            sb.Append(set[(int)(d % 64)]);

            return sb.ToString();

        }

        private static string GetString(byte[] hash)
        {
            string hashString = string.Empty;
            foreach (byte x in hash)
            {
                hashString += String.Format("{0:x2}", x);
            }
            return hashString;
        }
    }

    public class DatabaseHandler
    {
        string connectionString = "server=tcp:flightinginfra.database.windows.net,1433; Initial Catalog = test; Persist Security Info = False; User ID = vocadmin; Password = T!T@n1130; MultipleActiveResultSets = False; Encrypt = True; TrustServerCertificate = False; Connection Timeout = 30;";
        public SqlConnection connection;
        public DatabaseHandler()
        {
            connection = new SqlConnection(connectionString);
        }

        public void Close()
        {
            connection.Close();

        }
        public string getData(string key)
        {
            SqlCommand command;
            string sql = "select * from urlkey where id='" + key + "'";
            SqlDataReader dataReader;
            string url = string.Empty;
            try
            {
                connection.Open();

                command = new SqlCommand(sql, connection);
                dataReader = command.ExecuteReader();
                while (dataReader.Read())
                {
                    url = Convert.ToString(dataReader.GetValue(1));
                    break;
                }
                dataReader.Close();
                command.Dispose();
                connection.Close();
                return url;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                connection.Close();
            }
            return string.Empty;

        }

        public int SetData(string key, string url)
        {
            SqlCommand command;
            string sql = "insert into urlkey (id,url)  values ('" + key + "','" + url + "')";
            try
            {
                connection.Open();

                command = new SqlCommand(sql, connection);
                command.ExecuteNonQuery();
                command.Dispose();
                connection.Close();
            }
            catch (SqlException ex)
            {
                connection.Close();
                Console.WriteLine(ex.ToString());
                if (ex.ErrorCode == -2146232060)
                {
                    return 1;
                }
                return -1;
            }
            return 0;
        }
    }
}