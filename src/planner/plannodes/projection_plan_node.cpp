#include "planner/plannodes/projection_plan_node.h"

#include <memory>
#include <vector>

#include "common/json.h"

namespace terrier::planner {

common::hash_t ProjectionPlanNode::Hash() const {
  common::hash_t hash = AbstractPlanNode::Hash();

  // Nothing for us to do here!

  return hash;
}

bool ProjectionPlanNode::operator==(const AbstractPlanNode &rhs) const {
  // Since this node type does not have any internal members of its own,
  // there is nothing for us to do here!

  return (AbstractPlanNode::operator==(rhs));
}

nlohmann::json ProjectionPlanNode::ToJson() const {
  nlohmann::json j = AbstractPlanNode::ToJson();
  return j;
}

std::vector<std::unique_ptr<parser::AbstractExpression>> ProjectionPlanNode::FromJson(const nlohmann::json &j) {
  std::vector<std::unique_ptr<parser::AbstractExpression>> exprs;
  auto e1 = AbstractPlanNode::FromJson(j);
  exprs.insert(exprs.end(), std::make_move_iterator(e1.begin()), std::make_move_iterator(e1.end()));
  return exprs;
}

DEFINE_JSON_BODY_DECLARATIONS(ProjectionPlanNode);

}  // namespace terrier::planner
