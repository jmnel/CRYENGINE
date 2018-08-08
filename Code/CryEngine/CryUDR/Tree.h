// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

// *INDENT-OFF* - <hard to read code and declarations due to inconsistent indentation>

namespace Cry
{
	namespace UDR
	{

		class CTree final : public ITree
		{
		public:

			explicit                    CTree();

			// ITree
			virtual const CNode&        GetRootNode() const override;
			virtual void                RegisterListener(ITreeListener* pListenerToRegister) override;
			virtual void                UnregisterListener(ITreeListener* pListenerToUnregister) override;
			// ~ITree

			CNode&                      GetRootNodeWritable();
			bool                        Save(const char* szXmlFilePath, IString& outError) const;
			bool                        Load(const char* szXmlFilePath, IString& outError);
			void                        OnNodeAdded(const INode& freshlyAddedNode) const;
			void                        OnBeforeNodeRemoved(const INode& nodeBeingRemoved) const;
			void                        OnAfterNodeRemoved(const void* pFormerAddressOfNode) const;

		private:

			CNode                       m_root;
			std::vector<ITreeListener*> m_listeners;
		};

	}
}