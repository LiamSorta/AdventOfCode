//http://adventofcode.com/day/5
//So I cheated here and used c# instead of C++ for the sake of keeping everything in one script
//Sue me.
//Also, credit to http://stackoverflow.com/users/132474/michael for MD5 lines, see the coffee cup lines
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.Windows.Forms;


namespace Day4
{
    class Day4
    {
        //STA Thread so I can use the clipboard, this isn't REALLY imporant but it was late and I didn't feel like
        //typing out the answer. 
        [STAThread]
        static void Main(string[] args)
        {
            //Initialization, @ on pw to prevent escaping
            string password = @"iwrupvqb", newPassword = "", encoded = "";
            int tryCount = 0;
            do
            {
                tryCount++;
                //Adds count to password (e.g password1, password2, password3 etc etc)
                newPassword = password + tryCount.ToString();

                //Generates MD5 hash of given password, including tryCount alteration
                byte[] encodedPassword = new UTF8Encoding().GetBytes(newPassword);                                  //c|_|                          
                byte[] hash = ((HashAlgorithm)CryptoConfig.CreateFromName("MD5")).ComputeHash(encodedPassword);     //c|_|   
                encoded = BitConverter.ToString(hash).Replace("-", string.Empty).ToLower();                         //c|_|   

            } while (encoded.Substring(0, 5) != "00000"); //Checks to see if the first 5 chars of the encoded password are 00000
            Console.WriteLine(tryCount);
            //Clipboard because it was 3am and I didn't feel like typing the numbers
            Clipboard.SetText(tryCount.ToString());
            Console.ReadLine();

        }
    }
}
