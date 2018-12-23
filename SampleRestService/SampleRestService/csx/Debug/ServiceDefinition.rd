<?xml version="1.0" encoding="utf-8"?>
<serviceModel xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" name="SampleRestService" generation="1" functional="0" release="0" Id="f4820805-1797-4ac2-ac52-301b5dfcb275" dslVersion="1.2.0.0" xmlns="http://schemas.microsoft.com/dsltools/RDSM">
  <groups>
    <group name="SampleRestServiceGroup" generation="1" functional="0" release="0">
      <componentports>
        <inPort name="SampleRestServiceWeb:Endpoint1" protocol="http">
          <inToChannel>
            <lBChannelMoniker name="/SampleRestService/SampleRestServiceGroup/LB:SampleRestServiceWeb:Endpoint1" />
          </inToChannel>
        </inPort>
      </componentports>
      <settings>
        <aCS name="SampleRestServiceWeb:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/SampleRestService/SampleRestServiceGroup/MapSampleRestServiceWeb:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </maps>
        </aCS>
        <aCS name="SampleRestServiceWebInstances" defaultValue="[1,1,1]">
          <maps>
            <mapMoniker name="/SampleRestService/SampleRestServiceGroup/MapSampleRestServiceWebInstances" />
          </maps>
        </aCS>
        <aCS name="SampleRestServiceWorker:Microsoft.ServiceBus.ConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/SampleRestService/SampleRestServiceGroup/MapSampleRestServiceWorker:Microsoft.ServiceBus.ConnectionString" />
          </maps>
        </aCS>
        <aCS name="SampleRestServiceWorker:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="">
          <maps>
            <mapMoniker name="/SampleRestService/SampleRestServiceGroup/MapSampleRestServiceWorker:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </maps>
        </aCS>
        <aCS name="SampleRestServiceWorkerInstances" defaultValue="[1,1,1]">
          <maps>
            <mapMoniker name="/SampleRestService/SampleRestServiceGroup/MapSampleRestServiceWorkerInstances" />
          </maps>
        </aCS>
      </settings>
      <channels>
        <lBChannel name="LB:SampleRestServiceWeb:Endpoint1">
          <toPorts>
            <inPortMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWeb/Endpoint1" />
          </toPorts>
        </lBChannel>
      </channels>
      <maps>
        <map name="MapSampleRestServiceWeb:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWeb/Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </setting>
        </map>
        <map name="MapSampleRestServiceWebInstances" kind="Identity">
          <setting>
            <sCSPolicyIDMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWebInstances" />
          </setting>
        </map>
        <map name="MapSampleRestServiceWorker:Microsoft.ServiceBus.ConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWorker/Microsoft.ServiceBus.ConnectionString" />
          </setting>
        </map>
        <map name="MapSampleRestServiceWorker:Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" kind="Identity">
          <setting>
            <aCSMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWorker/Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" />
          </setting>
        </map>
        <map name="MapSampleRestServiceWorkerInstances" kind="Identity">
          <setting>
            <sCSPolicyIDMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWorkerInstances" />
          </setting>
        </map>
      </maps>
      <components>
        <groupHascomponents>
          <role name="SampleRestServiceWeb" generation="1" functional="0" release="0" software="C:\Users\mayada\Source\Repos\SampleRestService\SampleRestService\csx\Debug\roles\SampleRestServiceWeb" entryPoint="base\x64\WaHostBootstrapper.exe" parameters="base\x64\WaIISHost.exe " memIndex="-1" hostingEnvironment="frontendadmin" hostingEnvironmentVersion="2">
            <componentports>
              <inPort name="Endpoint1" protocol="http" portRanges="80" />
            </componentports>
            <settings>
              <aCS name="Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="" />
              <aCS name="__ModelData" defaultValue="&lt;m role=&quot;SampleRestServiceWeb&quot; xmlns=&quot;urn:azure:m:v1&quot;&gt;&lt;r name=&quot;SampleRestServiceWeb&quot;&gt;&lt;e name=&quot;Endpoint1&quot; /&gt;&lt;/r&gt;&lt;r name=&quot;SampleRestServiceWorker&quot; /&gt;&lt;/m&gt;" />
            </settings>
            <resourcereferences>
              <resourceReference name="DiagnosticStore" defaultAmount="[4096,4096,4096]" defaultSticky="true" kind="Directory" />
              <resourceReference name="EventStore" defaultAmount="[1000,1000,1000]" defaultSticky="false" kind="LogStore" />
            </resourcereferences>
          </role>
          <sCSPolicy>
            <sCSPolicyIDMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWebInstances" />
            <sCSPolicyUpdateDomainMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWebUpgradeDomains" />
            <sCSPolicyFaultDomainMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWebFaultDomains" />
          </sCSPolicy>
        </groupHascomponents>
        <groupHascomponents>
          <role name="SampleRestServiceWorker" generation="1" functional="0" release="0" software="C:\Users\mayada\Source\Repos\SampleRestService\SampleRestService\csx\Debug\roles\SampleRestServiceWorker" entryPoint="base\x64\WaHostBootstrapper.exe" parameters="base\x64\WaWorkerHost.exe " memIndex="-1" hostingEnvironment="consoleroleadmin" hostingEnvironmentVersion="2">
            <settings>
              <aCS name="Microsoft.ServiceBus.ConnectionString" defaultValue="" />
              <aCS name="Microsoft.WindowsAzure.Plugins.Diagnostics.ConnectionString" defaultValue="" />
              <aCS name="__ModelData" defaultValue="&lt;m role=&quot;SampleRestServiceWorker&quot; xmlns=&quot;urn:azure:m:v1&quot;&gt;&lt;r name=&quot;SampleRestServiceWeb&quot;&gt;&lt;e name=&quot;Endpoint1&quot; /&gt;&lt;/r&gt;&lt;r name=&quot;SampleRestServiceWorker&quot; /&gt;&lt;/m&gt;" />
            </settings>
            <resourcereferences>
              <resourceReference name="DiagnosticStore" defaultAmount="[4096,4096,4096]" defaultSticky="true" kind="Directory" />
              <resourceReference name="EventStore" defaultAmount="[1000,1000,1000]" defaultSticky="false" kind="LogStore" />
            </resourcereferences>
          </role>
          <sCSPolicy>
            <sCSPolicyIDMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWorkerInstances" />
            <sCSPolicyUpdateDomainMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWorkerUpgradeDomains" />
            <sCSPolicyFaultDomainMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWorkerFaultDomains" />
          </sCSPolicy>
        </groupHascomponents>
      </components>
      <sCSPolicy>
        <sCSPolicyUpdateDomain name="SampleRestServiceWebUpgradeDomains" defaultPolicy="[5,5,5]" />
        <sCSPolicyUpdateDomain name="SampleRestServiceWorkerUpgradeDomains" defaultPolicy="[5,5,5]" />
        <sCSPolicyFaultDomain name="SampleRestServiceWebFaultDomains" defaultPolicy="[2,2,2]" />
        <sCSPolicyFaultDomain name="SampleRestServiceWorkerFaultDomains" defaultPolicy="[2,2,2]" />
        <sCSPolicyID name="SampleRestServiceWebInstances" defaultPolicy="[1,1,1]" />
        <sCSPolicyID name="SampleRestServiceWorkerInstances" defaultPolicy="[1,1,1]" />
      </sCSPolicy>
    </group>
  </groups>
  <implements>
    <implementation Id="57a12387-5c87-47a9-a84e-12e8bb28f890" ref="Microsoft.RedDog.Contract\ServiceContract\SampleRestServiceContract@ServiceDefinition">
      <interfacereferences>
        <interfaceReference Id="bb85d7da-776c-48f7-a2fc-4adb707593b1" ref="Microsoft.RedDog.Contract\Interface\SampleRestServiceWeb:Endpoint1@ServiceDefinition">
          <inPort>
            <inPortMoniker name="/SampleRestService/SampleRestServiceGroup/SampleRestServiceWeb:Endpoint1" />
          </inPort>
        </interfaceReference>
      </interfacereferences>
    </implementation>
  </implements>
</serviceModel>