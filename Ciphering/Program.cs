using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Ciphering
{
    class Program
    {
        static void Main(string[] args)
        {
            SymmetricDemo();
            AsymmetricDemo();
        }

        public static void AsymmetricDemo()
        {
            // Create an instance of the RSA algorithm class  
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
            // Get the public keyy   
            string publicKey = rsa.ToXmlString(false); // false to get the public key   
            string privateKey = rsa.ToXmlString(true); // true to get the private key   

            // Call the encryptText method   
            EncryptText(publicKey, "Hello from C# Corner", "encryptedData.dat");

            // Call the decryptData method and print the result on the screen   
            Console.WriteLine("Decrypted message: {0}", DecryptData(privateKey, "encryptedData.dat"));
        }


        // Create a method to encrypt a text and save it to a specific file using a RSA algorithm public key   
        static void EncryptText(string publicKey, string text, string fileName)
        {
            // Convert the text to an array of bytes   
            UnicodeEncoding byteConverter = new UnicodeEncoding();
            byte[] dataToEncrypt = byteConverter.GetBytes(text);

            // Create a byte array to store the encrypted data in it   
            byte[] encryptedData;
            using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
            {
                // Set the rsa pulic key   
                rsa.FromXmlString(publicKey);

                // Encrypt the data and store it in the encyptedData Array   
                encryptedData = rsa.Encrypt(dataToEncrypt, false);
            }
            // Save the encypted data array into a file   
            File.WriteAllBytes(fileName, encryptedData);

            Console.WriteLine("Data has been encrypted");
        }

        // Method to decrypt the data withing a specific file using a RSA algorithm private key   
        static string DecryptData(string privateKey, string fileName)
        {
            // read the encrypted bytes from the file   
            byte[] dataToDecrypt = File.ReadAllBytes(fileName);

            // Create an array to store the decrypted data in it   
            byte[] decryptedData;
            using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
            {
                // Set the private key of the algorithm   
                rsa.FromXmlString(privateKey);
                decryptedData = rsa.Decrypt(dataToDecrypt, false);
            }

            // Get the string value from the decryptedData byte array   
            UnicodeEncoding byteConverter = new UnicodeEncoding();
            return byteConverter.GetString(decryptedData);
        }
        public static void SymmetricDemo()
        {
            SymmetricAlgorithm aes = new AesManaged();
            byte[] key = aes.Key;
            Console.WriteLine("Enter text to cipher");
            string message = Console.ReadLine();
            EncryptData(aes, message, "encrypted.data");
            string dmesssage = DecryptData(aes, "encrypted.data");
            Console.WriteLine(dmesssage);
        }

        private static string DecryptData(SymmetricAlgorithm aesAlgorithm, string fileName)
        {
            ICryptoTransform decryptor = aesAlgorithm.CreateDecryptor(aesAlgorithm.Key, aesAlgorithm.IV);

            // Read the encrypted bytes from the file   
            byte[] encryptedDataBuffer = File.ReadAllBytes(fileName);

            // Create a memorystream to write the decrypted data in it   
            using (MemoryStream ms = new MemoryStream(encryptedDataBuffer))
            {
                using (CryptoStream cs = new CryptoStream(ms, decryptor, CryptoStreamMode.Read))
                {
                    using (StreamReader reader = new StreamReader(cs))
                    {
                        // Reutrn all the data from the streamreader   
                        return reader.ReadToEnd();
                    }
                }
            }

        }

        private static void EncryptData(SymmetricAlgorithm aesAlgorithm, string message, string fileName)
        {
            ICryptoTransform encryptor = aesAlgorithm.CreateEncryptor(aesAlgorithm.Key, aesAlgorithm.IV);

            // Create a memory stream to save the encrypted data in it  
            using (MemoryStream ms = new MemoryStream())
            {
                using (CryptoStream cs = new CryptoStream(ms, encryptor, CryptoStreamMode.Write))
                {
                    using (StreamWriter writer = new StreamWriter(cs))
                    {
                        // Write the text in the stream writer   
                        writer.Write(message);
                    }
                }

                // Get the result as a byte array from the memory stream   
                byte[] encryptedDataBuffer = ms.ToArray();

                // Write the data to a file   
                File.WriteAllBytes(fileName, encryptedDataBuffer);
            }
        }
    }

}
