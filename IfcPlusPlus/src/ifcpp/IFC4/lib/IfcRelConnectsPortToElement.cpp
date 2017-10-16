/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcDistributionElement.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPort.h"
#include "ifcpp/IFC4/include/IfcRelConnectsPortToElement.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelConnectsPortToElement 
IfcRelConnectsPortToElement::IfcRelConnectsPortToElement() {}
IfcRelConnectsPortToElement::IfcRelConnectsPortToElement( int id ) { m_id = id; }
IfcRelConnectsPortToElement::~IfcRelConnectsPortToElement() {}
shared_ptr<IfcPPObject> IfcRelConnectsPortToElement::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcRelConnectsPortToElement> copy_self( new IfcRelConnectsPortToElement() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createGUID32_wstr().c_str() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_RelatingPort ) { copy_self->m_RelatingPort = dynamic_pointer_cast<IfcPort>( m_RelatingPort->getDeepCopy(options) ); }
	if( m_RelatedElement ) { copy_self->m_RelatedElement = dynamic_pointer_cast<IfcDistributionElement>( m_RelatedElement->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelConnectsPortToElement::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCRELCONNECTSPORTTOELEMENT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RelatingPort ) { stream << "#" << m_RelatingPort->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatedElement ) { stream << "#" << m_RelatedElement->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelConnectsPortToElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
const std::wstring IfcRelConnectsPortToElement::toString() const { return L"IfcRelConnectsPortToElement"; }
void IfcRelConnectsPortToElement::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelConnectsPortToElement, expecting 6, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readEntityReference( args[4], m_RelatingPort, map );
	readEntityReference( args[5], m_RelatedElement, map );
}
void IfcRelConnectsPortToElement::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcRelConnects::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingPort", m_RelatingPort ) );
	vec_attributes.push_back( std::make_pair( "RelatedElement", m_RelatedElement ) );
}
void IfcRelConnectsPortToElement::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelConnectsPortToElement::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelConnectsPortToElement> ptr_self = dynamic_pointer_cast<IfcRelConnectsPortToElement>( ptr_self_entity );
	if( !ptr_self ) { throw IfcPPException( "IfcRelConnectsPortToElement::setInverseCounterparts: type mismatch" ); }
	if( m_RelatedElement )
	{
		m_RelatedElement->m_HasPorts_inverse.push_back( ptr_self );
	}
	if( m_RelatingPort )
	{
		m_RelatingPort->m_ContainedIn_inverse.push_back( ptr_self );
	}
}
void IfcRelConnectsPortToElement::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	if( m_RelatedElement )
	{
		std::vector<weak_ptr<IfcRelConnectsPortToElement> >& HasPorts_inverse = m_RelatedElement->m_HasPorts_inverse;
		for( auto it_HasPorts_inverse = HasPorts_inverse.begin(); it_HasPorts_inverse != HasPorts_inverse.end(); )
		{
			shared_ptr<IfcRelConnectsPortToElement> self_candidate( *it_HasPorts_inverse );
			if( self_candidate.get() == this )
			{
				it_HasPorts_inverse= HasPorts_inverse.erase( it_HasPorts_inverse );
			}
			else
			{
				++it_HasPorts_inverse;
			}
		}
	}
	if( m_RelatingPort )
	{
		std::vector<weak_ptr<IfcRelConnectsPortToElement> >& ContainedIn_inverse = m_RelatingPort->m_ContainedIn_inverse;
		for( auto it_ContainedIn_inverse = ContainedIn_inverse.begin(); it_ContainedIn_inverse != ContainedIn_inverse.end(); )
		{
			shared_ptr<IfcRelConnectsPortToElement> self_candidate( *it_ContainedIn_inverse );
			if( self_candidate.get() == this )
			{
				it_ContainedIn_inverse= ContainedIn_inverse.erase( it_ContainedIn_inverse );
			}
			else
			{
				++it_ContainedIn_inverse;
			}
		}
	}
}