using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MSP2.Models
{
    public class Emp
    {
        public string alias { get; set; }
        public string fcm { get; set; }
        public int buildingLoc { get; set; }
        public long token { get; set; }
        public Emp(string alias, string fcm, int loc = 2)
        {
            this.alias = alias;
            this.fcm = fcm;
            this.buildingLoc = loc;
        }

    }
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

    }
}