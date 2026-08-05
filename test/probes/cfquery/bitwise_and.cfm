<!--- Seen in: Mura CMS core/mura/dbUpdates/*.cfm (SQL Server DDL)
      AND status & 2048 = 2048 --->
<cfquery>
IF NOT EXISTS (SELECT 1
	FROM sysindexes
	WHERE id = object_id(N'[dbo].[tplugins]')
	AND status & 2048 = 2048 )
ALTER TABLE [dbo].[tplugins] WITH NOCHECK ADD
	CONSTRAINT [PK_tplugins_pluginID] PRIMARY KEY CLUSTERED ( [pluginID] ) ON [PRIMARY]
</cfquery>
