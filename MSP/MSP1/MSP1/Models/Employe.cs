using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MSP1.Models
{
    public class ForeignData
    {
        //public int EmployeeId
        //{
        //    get;
        //    set;
        //}
        public string EmpAlias
        {
            get;
            set;
        }
        public string fcm_token
        {
            get;
            set;
        }
        public string reportAbuse
        {
            get;
            set;
        }
        public string operation //exit/entry/login/reportabuse
        {
            get;
            set;
        }
        public int gateNumber
        {
            get;
            set;
        }
        public int empId
        {
            get;
            set;
        }

        //public string Department
        //{
        //    get;
        //    set;
        //}
    }
}