<?xml version="1.0" encoding="utf-8"?>
<serviceModel xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" name="ContosoAdsCloudService" generation="1" functional="0" release="0" Id="4c2bf5aa-a32c-4f96-a964-18e98b129c73" dslVersion="1.2.0.0" xmlns="http://schemas.microsoft.com/dsltools/RDSM">
  <groups>
    <group name="ContosoAdsCloudServiceGroup" generation="1" functional="0" release="0">
      <componentports>
        <inPort name="ContosoAdsWeb:Endpoint1" protocol="http">
          <inToChannel>
            <lBChannelMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/LB:ContosoAdsWeb:Endpoint1" />
          </inToChannel>
        </inPort>
      </componentports>
      <settings>
        <aCS name="ContosoAdsWeb:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWeb:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </maps>
        </aCS>
        <aCS name="ContosoAdsWeb:StorageConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWeb:StorageConnectionString" />
          </maps>
        </aCS>
        <aCS name="ContosoAdsWebInstances" defaultValue="[1,1,1]">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWebInstances" />
          </maps>
        </aCS>
        <aCS name="ContosoAdsWorker:ContosoAdsDbConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWorker:ContosoAdsDbConnectionString" />
          </maps>
        </aCS>
        <aCS name="ContosoAdsWorker:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWorker:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </maps>
        </aCS>
        <aCS name="ContosoAdsWorker:StorageConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWorker:StorageConnectionString" />
          </maps>
        </aCS>
        <aCS name="ContosoAdsWorkerInstances" defaultValue="[1,1,1]">
          <maps>
            <mapMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/MapContosoAdsWorkerInstances" />
          </maps>
        </aCS>
      </settings>
      <channels>
        <lBChannel name="LB:ContosoAdsWeb:Endpoint1">
          <toPorts>
            <inPortMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWeb/Endpoint1" />
          </toPorts>
        </lBChannel>
      </channels>
      <maps>
        <map name="MapContosoAdsWeb:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWeb/Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </setting>
        </map>
        <map name="MapContosoAdsWeb:StorageConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWeb/StorageConnectionString" />
          </setting>
        </map>
        <map name="MapContosoAdsWebInstances" kind="Identity">
          <setting>
            <sCSPolicyIDMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWebInstances" />
          </setting>
        </map>
        <map name="MapContosoAdsWorker:ContosoAdsDbConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorker/ContosoAdsDbConnectionString" />
          </setting>
        </map>
        <map name="MapContosoAdsWorker:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorker/Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </setting>
        </map>
        <map name="MapContosoAdsWorker:StorageConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorker/StorageConnectionString" />
          </setting>
        </map>
        <map name="MapContosoAdsWorkerInstances" kind="Identity">
          <setting>
            <sCSPolicyIDMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorkerInstances" />
          </setting>
        </map>
      </maps>
      <components>
        <groupHascomponents>
          <role name="ContosoAdsWeb" generation="1" functional="0" release="0" software="C:\Users\mayada\work\cloudService\C#\ContosoAdsCloudService\csx\Debug\roles\ContosoAdsWeb" entryPoint="base\x64\WaHostBootstrapper.exe" parameters="base\x64\WaIISHost.exe " memIndex="-1" hostingEnvironment="frontendadmin" hostingEnvironmentVersion="2">
            <componentports>
              <inPort name="Endpoint1" protocol="http" portRanges="80" />
            </componentports>
            <settings>
              <aCS name="Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="" />
              <aCS name="StorageConnectionString" defaultValue="" />
              <aCS name="__ModelData" defaultValue="&lt;m role=&quot;ContosoAdsWeb&quot; xmlns=&quot;urn:azure:m:v1&quot;&gt;&lt;r name=&quot;ContosoAdsWeb&quot;&gt;&lt;e name=&quot;Endpoint1&quot; /&gt;&lt;/r&gt;&lt;r name=&quot;ContosoAdsWorker&quot; /&gt;&lt;/m&gt;" />
            </settings>
            <resourcereferences>
              <resourceReference name="DiagnosticStore" defaultAmount="[4096,4096,4096]" defaultSticky="true" kind="Directory" />
              <resourceReference name="EventStore" defaultAmount="[1000,1000,1000]" defaultSticky="false" kind="LogStore" />
            </resourcereferences>
          </role>
          <sCSPolicy>
            <sCSPolicyIDMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWebInstances" />
            <sCSPolicyUpdateDomainMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWebUpgradeDomains" />
            <sCSPolicyFaultDomainMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWebFaultDomains" />
          </sCSPolicy>
        </groupHascomponents>
        <groupHascomponents>
          <role name="ContosoAdsWorker" generation="1" functional="0" release="0" software="C:\Users\mayada\work\cloudService\C#\ContosoAdsCloudService\csx\Debug\roles\ContosoAdsWorker" entryPoint="base\x64\WaHostBootstrapper.exe" parameters="base\x64\WaWorkerHost.exe " memIndex="-1" hostingEnvironment="consoleroleadmin" hostingEnvironmentVersion="2">
            <settings>
              <aCS name="ContosoAdsDbConnectionString" defaultValue="" />
              <aCS name="Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="" />
              <aCS name="StorageConnectionString" defaultValue="" />
              <aCS name="__ModelData" defaultValue="&lt;m role=&quot;ContosoAdsWorker&quot; xmlns=&quot;urn:azure:m:v1&quot;&gt;&lt;r name=&quot;ContosoAdsWeb&quot;&gt;&lt;e name=&quot;Endpoint1&quot; /&gt;&lt;/r&gt;&lt;r name=&quot;ContosoAdsWorker&quot; /&gt;&lt;/m&gt;" />
            </settings>
            <resourcereferences>
              <resourceReference name="DiagnosticStore" defaultAmount="[4096,4096,4096]" defaultSticky="true" kind="Directory" />
              <resourceReference name="EventStore" defaultAmount="[1000,1000,1000]" defaultSticky="false" kind="LogStore" />
            </resourcereferences>
          </role>
          <sCSPolicy>
            <sCSPolicyIDMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorkerInstances" />
            <sCSPolicyUpdateDomainMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorkerUpgradeDomains" />
            <sCSPolicyFaultDomainMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWorkerFaultDomains" />
          </sCSPolicy>
        </groupHascomponents>
      </components>
      <sCSPolicy>
        <sCSPolicyUpdateDomain name="ContosoAdsWebUpgradeDomains" defaultPolicy="[5,5,5]" />
        <sCSPolicyUpdateDomain name="ContosoAdsWorkerUpgradeDomains" defaultPolicy="[5,5,5]" />
        <sCSPolicyFaultDomain name="ContosoAdsWebFaultDomains" defaultPolicy="[2,2,2]" />
        <sCSPolicyFaultDomain name="ContosoAdsWorkerFaultDomains" defaultPolicy="[2,2,2]" />
        <sCSPolicyID name="ContosoAdsWebInstances" defaultPolicy="[1,1,1]" />
        <sCSPolicyID name="ContosoAdsWorkerInstances" defaultPolicy="[1,1,1]" />
      </sCSPolicy>
    </group>
  </groups>
  <implements>
    <implementation Id="cb6eb582-554e-4aab-ac59-60ebb2af787c" ref="Microsoft.RedDog.Contract\ServiceContract\ContosoAdsCloudServiceContract@ServiceDefinition">
      <interfacereferences>
        <interfaceReference Id="a52bbd77-6d27-4641-904f-831a51425042" ref="Microsoft.RedDog.Contract\Interface\ContosoAdsWeb:Endpoint1@ServiceDefinition">
          <inPort>
            <inPortMoniker name="/ContosoAdsCloudService/ContosoAdsCloudServiceGroup/ContosoAdsWeb:Endpoint1" />
          </inPort>
        </interfaceReference>
      </interfacereferences>
    </implementation>
  </implements>
</serviceModel>