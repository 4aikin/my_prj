#include "date.h"
#include "node.h"

using namespace std;

bool EmptyNode::Evaluate(const Date& date, const string& event) const  {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& datee, const string& eventt) const  {
	if (cmp == Comparison::Equal)			{ return datee == date; }
	if (cmp == Comparison::NotEqual)		{ return datee != date; }
	if (cmp == Comparison::Less)			{ return datee < date; }
	if (cmp == Comparison::LessOrEqual)		{ return datee <= date; }
	if (cmp == Comparison::Greater)			{ return datee > date; }
	if (cmp == Comparison::GreaterOrEqual)	{ return datee >= date; }
}

bool EventComparisonNode::Evaluate(const Date& datee, const string& eventt) const  {
	if (cmp == Comparison::Equal)			{ return eventt == event; }
	if (cmp == Comparison::NotEqual)		{ return eventt != event; }
	if (cmp == Comparison::Less)			{ return eventt < event; }
	if (cmp == Comparison::LessOrEqual)		{ return eventt <= event; }
	if (cmp == Comparison::Greater)			{ return eventt > event; }
	if (cmp == Comparison::GreaterOrEqual)  { return eventt >= event; }
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const  {
	if (lo == LogicalOperation::And) {
		return left->Evaluate(date, event) && right->Evaluate(date, event);
	} else return left->Evaluate(date, event) || right->Evaluate(date, event);
}

