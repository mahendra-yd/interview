using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Web;
using MSP2.Models;

namespace MSP2.ParkingMgr
{
    public class Location
    {
        public int lane, row, floor, ID, building;
        public double lat, longt;
        public Location(int l = 0, int r = 0, int f = 0, double lat = 0, double longt = 0, int ID = 0, int building = 0)
        {
            lane = l;
            row = r;
            floor = f;
            this.lat = lat;
            this.longt = longt;
            this.ID = ID;
            this.building = building;
        }
    }

    public class Vehicle
    {
        public string name;
        public int type;
        public int building;
        public Vehicle(string name = "", int building = 1)
        {
            this.name = name;
            this.building = building;
            type = 4;
        }
    }

    public class Slot
    {
        public int type;
        public bool occupied;
        public Location loc;
        public Vehicle vehicle;
        public Slot(Location loc_)
        {
            loc = loc_;
            occupied = false;
        }
        public Location getLocation() { return loc; }
        public void park(Vehicle v) { vehicle = v; occupied = true; }
        public Vehicle unpark() { occupied = false; return vehicle; }
        public long hasCode() { return 100; ; }
    }
    public sealed class ParkingLot
    {
        static ParkingLot()
        {

        }
        private static readonly ParkingLot instance = new ParkingLot();

        public static ParkingLot Instance
        {
            get
            {
                return instance;
            }
        }
        public static int slotInBuildingA = 1;
        public static int slotInBuildingB = 1;
        public static int slotInBuildingC = 1;
        public static Dictionary<string, Emp> fcm_alias = new Dictionary<string, Emp>(100);
        Dictionary<long, Slot> occupiedSlot;//= new Dictionary<long, Slot>();//map
        List<Slot> BuildingASlots;
        List<Slot> BuildingBSlots;
        List<Slot> BuildingCSlots;
        List<List<Slot>> allLocation;
        public Dictionary<int, Location> idgeoloc;
        public void createSlots()
        {
            int counterToSlot = 0;
            for (int i = 0; i < slotInBuildingA; i++)
            {

                BuildingASlots.Add(new Slot(idgeoloc[counterToSlot]));
                counterToSlot++;
            }
            for (int i = 0; i < slotInBuildingB; i++)
            {
                BuildingBSlots.Add(new Slot(idgeoloc[counterToSlot]));
                counterToSlot++;
            }
            for (int i = 0; i < slotInBuildingC; i++)
            {
                BuildingCSlots.Add(new Slot(idgeoloc[counterToSlot]));
                counterToSlot++;
            }
            allLocation.Add(BuildingASlots); //;, BuildingBSlots, BuildingCSlots);
            allLocation.Add(BuildingBSlots);
            allLocation.Add(BuildingCSlots);
        }
        private ParkingLot()
        {
            slotInBuildingA = 1;
            slotInBuildingB = 1;
            slotInBuildingC = 1;

            occupiedSlot = new Dictionary<long, Slot>();//map
            BuildingASlots = new List<Slot>(slotInBuildingA);
            BuildingBSlots = new List<Slot>(slotInBuildingB);
            BuildingCSlots = new List<Slot>(slotInBuildingC);
            allLocation = new List<List<Slot>>(3);
            idgeoloc = new Dictionary<int, Location>(300);

            using (TextReader reader = File.OpenText("c:\\test\\text1.txt"))
            {
                string text;
                int counter = 0;
                while ((text = reader.ReadLine()) != null)
                {
                    string[] locline = text.Split(',');
                    int x = int.Parse(locline[0]);
                    Location loc = new Location(int.Parse(locline[0]), int.Parse(locline[1]), int.Parse(locline[2]), double.Parse(locline[3]), double.Parse(locline[4]), int.Parse(locline[5]), int.Parse(locline[6]));
                    idgeoloc[counter++] = loc;
                }
            }
            createSlots();
        }
        public Slot getFirstEmptySlot(int loc)
        {
            for (int i = 0; i < 3; i++)
            {
                var j = allLocation[(loc + i) % 3];
                foreach (var k in j)
                {
                    if (k.occupied == false)
                        return k;
                }
            }
            return null;
        }

        public long park(Vehicle vehicle)
        {
            Slot slot = getFirstEmptySlot(vehicle.building);
            if (slot != null)
            {
                slot.park(vehicle);
                long ret = slot.hasCode();
                occupiedSlot[ret] = slot;
                // SEnd loc in mobile app ##############################
                using (var httpClient = new HttpClient())
                {
                    string baseUrl = "https://fcm.googleapis.com/fcm/send";
                    // httpClient.BaseAddress = new Uri("http://example.com/");

                    httpClient.DefaultRequestHeaders.Add("Accept", "application/json");
                    httpClient.DefaultRequestHeaders.TryAddWithoutValidation("Content-Type", "application/json; charset=utf-8");
                    // httpClient.DefaultRequestHeaders.Add("Content-Type", "application/json");
                    httpClient.DefaultRequestHeaders.Authorization = new System.Net.Http.Headers.AuthenticationHeaderValue("key", "=AAAAfknP_M0:APA91bGNbYuq26vnCNvCL3mOhGRsC1zx3EokyWALVLCHQVAS3yCDZC6VDQMWk9X0KcMnGkkQWO-LsTb2Vhfm0qnz90RoJlAihjcRF4pwz3-SRiSZFlbjkgB2vX8SSFSVSX6xuvX6EpQp");

                    var requestdata = new
                    {
                        data = new
                        {
                            lat = "17.431119",
                            lon = "78.341831"
                        },
                        to = "ct8AherW018:APA91bHHjYGQfsIxh_PrdlmbhHt4xZ8B-tmS8dgjqXeFpPExoxHOpoUfHZrE3PPrxp0VUV_TgYRTShCysG1OgtudCbvUMagP2fprFo8Hpgww6c5cgSPE0yaZ_6CjlFR40HfyJ_Fm0TBT"
                    };
                    HttpRequestMessage request = new HttpRequestMessage(HttpMethod.Post, baseUrl);
                    request.Content = new StringContent(JsonConvert.SerializeObject(requestdata).ToString(),
                                                        Encoding.UTF8,
                                                        "application/json");//CONTENT-TYPE header

                    var res = httpClient.SendAsync(request).Result;
                    // var result = httpClient.PostAsJsonAsync(baseUrl, JsonConvert.SerializeObject(requestdata).ToString()).Result;
                }
                //################################
                return ret;
            }
            return 0;
        }
        public Vehicle unpark(long ret)
        {
            Slot slot = occupiedSlot[ret];
            occupiedSlot.Remove(ret);
            return slot.unpark();
        }
    }

}