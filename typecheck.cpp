#include "typecheck.hpp"

// Defines the function used to throw type errors. The possible
// type errors are defined as an enumeration in the header file.
void typeError(TypeErrorCode code) {
  switch (code) {
    case undefined_variable:
      std::cerr << "Undefined variable." << std::endl;
      break;
    case undefined_method:
      std::cerr << "Method does not exist." << std::endl;
      break;
    case undefined_class:
      std::cerr << "Class does not exist." << std::endl;
      break;
    case undefined_member:
      std::cerr << "Class member does not exist." << std::endl;
      break;
    case not_object:
      std::cerr << "Variable is not an object." << std::endl;
      break;
    case expression_type_mismatch:
      std::cerr << "Expression types do not match." << std::endl;
      break;
    case argument_number_mismatch:
      std::cerr << "Method called with incorrect number of arguments." << std::endl;
      break;
    case argument_type_mismatch:
      std::cerr << "Method called with argument of incorrect type." << std::endl;
      break;
    case while_predicate_type_mismatch:
      std::cerr << "Predicate of while loop is not boolean." << std::endl;
      break;
    case repeat_predicate_type_mismatch:
      std::cerr << "Predicate of repeat loop is not boolean." << std::endl;
      break;
    case if_predicate_type_mismatch:
      std::cerr << "Predicate of if statement is not boolean." << std::endl;
      break;
    case assignment_type_mismatch:
      std::cerr << "Left and right hand sides of assignment types mismatch." << std::endl;
      break;
    case return_type_mismatch:
      std::cerr << "Return statement type does not match declared return type." << std::endl;
      break;
    case constructor_returns_type:
      std::cerr << "Class constructor returns a value." << std::endl;
      break;
    case no_main_class:
      std::cerr << "The \"Main\" class was not found." << std::endl;
      break;
    case main_class_members_present:
      std::cerr << "The \"Main\" class has members." << std::endl;
      break;
    case no_main_method:
      std::cerr << "The \"Main\" class does not have a \"main\" method." << std::endl;
      break;
    case main_method_incorrect_signature:
      std::cerr << "The \"main\" method of the \"Main\" class has an incorrect signature." << std::endl;
      break;
  }
  exit(1);
}

// TypeCheck Visitor Functions: These are the functions you will
// complete to build the symbol table and type check the program.
// Not all functions must have code, many may be left empty.

void TypeCheck::visitProgramNode(ProgramNode* node) {
  this->classTable = new ClassTable();
  node->visit_children(this);

  if((*classTable).find("Main") == (*classTable).end()) {
    typeError(no_main_class);
  }
  else {
    if((*(*classTable)["Main"].members).size() != 0) {
      typeError(main_class_members_present);
    }
    if((*(*classTable)["Main"].methods).find("main") == (*(*classTable)["Main"].methods).end()) {
      typeError(no_main_method);
    }
    else {
      if((*(*classTable)["Main"].methods)["main"].returnType.baseType != bt_none) {
        typeError(main_method_incorrect_signature);
      }
    }
  }
}

void TypeCheck::visitClassNode(ClassNode* node) {
  ClassInfo ci;
  if(node->identifier_2 == NULL) {
    ci.superClassName = "";
  }
  else {
    if((*classTable).find(node->identifier_2->name) == (*classTable).end()) {
      typeError(undefined_class);
    }
    ci.superClassName = node->identifier_2->name;
  }
  this->currentClassName = node->identifier_1->name;
  this->currentMemberOffset = 0;
  this->currentLocalOffset = 0;
  this->currentMethodTable = new MethodTable();
  this->currentVariableTable = new VariableTable();
  ci.methods = this->currentMethodTable;
  ci.members = this->currentVariableTable;
  (*classTable)[node->identifier_1->name]= ci;
  node->visit_children(this);
  (*classTable)[node->identifier_1->name].membersSize = 4* (*classTable)[node->identifier_1->name].members->size();
}

void TypeCheck::visitMethodNode(MethodNode* node) {
  this->currentParameterOffset = 12;
  this->currentLocalOffset =  -4;

  MethodInfo mi;
  CompoundType ct;
  this->currentVariableTable = new VariableTable();
  mi.variables = this->currentVariableTable;
  mi.parameters = new std::list<CompoundType>();
  node->visit_children(this);

  for (std::list<ParameterNode*>::iterator it=node->parameter_list->begin(); it != node->parameter_list->end(); ++it) {
    CompoundType param;
    param.baseType = (*it)->basetype;
    param.objectClassName =   (*it)->type->objectClassName;
    mi.parameters->push_back(param);
  }

  ct.baseType = node->type->basetype;
  ct.objectClassName = node->type->objectClassName;
  mi.returnType = ct;

  (*currentMethodTable)[node->identifier->name] = mi;

  if(node->identifier->name == this->currentClassName) {
    if(node->type->basetype != bt_none) {
      typeError(constructor_returns_type);
    }
  }                            

  if(node->type->basetype == bt_none) {
    if(node->methodbody->returnstatement != NULL) {
      typeError(return_type_mismatch);
    }
  }
  else { 
    if(node->methodbody->returnstatement == NULL) {
      typeError(return_type_mismatch);
    }
    else {
      if(node->type->basetype != node->methodbody->returnstatement->basetype) {
        typeError(return_type_mismatch);  
      }
      if(node->type->basetype == bt_object) {
        if(node->type->objectClassName != node->methodbody->returnstatement->objectClassName) {
          typeError(return_type_mismatch);
        }
      }
    }
  }
  (*currentMethodTable)[node->identifier->name].localsSize = 4*(mi.variables->size() - mi.parameters->size());
}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {
  node->visit_children(this);
  node->returnstatement->basetype;
}

void TypeCheck::visitParameterNode(ParameterNode* node) {
  node->visit_children(this);
  VariableInfo vi;
  CompoundType ct;
  node->basetype = node->type->basetype;
  node->objectClassName =  (node->basetype == bt_object ? node->type->objectClassName : "");
  ct.baseType = node->basetype;
  ct.objectClassName = (node->basetype == bt_object ? node->type->objectClassName : "");
  vi.type = ct;

  vi.offset = this->currentParameterOffset;
  this->currentParameterOffset = this->currentParameterOffset+4;

  vi.size = 4;
  
  (*currentVariableTable)[node->identifier->name] = vi;
}

void TypeCheck::visitDeclarationNode(DeclarationNode* node) {
  node->visit_children(this);
  node->basetype = node->type->basetype;
  if(node->basetype == bt_object) {
    node->objectClassName =  node->type->objectClassName;
  }
  for (std::list<IdentifierNode*>::iterator it=node->identifier_list->begin(); it != node->identifier_list->end(); ++it) {
    VariableInfo vi;
    CompoundType ct;
    ct.baseType = node->basetype;
    if(node->basetype == bt_object) {
      if((*classTable).find(node->type->objectClassName) == (*classTable).end()) {
        typeError(undefined_class);
      } 
      ct.objectClassName = node->type->objectClassName;
    }
    else {
      ct.objectClassName = "";
    }
    vi.type = ct;
    if(this->currentLocalOffset == 0) {
      vi.offset = this->currentMemberOffset;
      this->currentMemberOffset = this->currentMemberOffset + 4;
    }
    else {
      vi.offset = this->currentLocalOffset;
      this->currentLocalOffset = this->currentLocalOffset - 4;
    }
    
    vi.size = 4;
    (*currentVariableTable)[(*it)->name] = vi; 
  }
}

void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
  node->visit_children(this);
  
  node->basetype = node->expression->basetype;
  if(node->basetype == bt_object){
    node->objectClassName = node->expression->objectClassName;
  }
}

void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
  node->visit_children(this);
  bool found;
  bool memfound; 
  std::string className;
  std::string refClass;
  VariableTable* mem;
  std::string name;
  std::string obj;

  if(node->identifier_2 == NULL) {
    if((*currentVariableTable).find(node->identifier_1->name) != (*currentVariableTable).end()) {
      node->basetype = (*currentVariableTable)[node->identifier_1->name].type.baseType;
      node->objectClassName = (*currentVariableTable)[node->identifier_1->name].type.objectClassName;
    }
    else {
      found = false;
      className = this->currentClassName;
      while(className != "" && !found) {
        mem = (*classTable)[className].members;
        name = node->identifier_1->name;
        if(mem->find(name) != mem->end()) {
          found = true;
          node->basetype = (*mem)[name].type.baseType;
          node->objectClassName =  (*mem)[name].type.objectClassName;
          break;
        }  
        className = (*classTable)[className].superClassName;
      }

      if(found == false) {
        typeError(undefined_variable);
      }
    } 
  }
  else { 
    found = false;
    memfound = false;
    name = node->identifier_1->name;
    
    if((*currentVariableTable).find(name) != (*currentVariableTable).end()) {
      className= (*currentVariableTable)[name].type.objectClassName;
      found = true;
      refClass = className;
      if((*currentVariableTable)[name].type.baseType != bt_object) {
        typeError(not_object);
      }
    }
    else {
      className = this->currentClassName;
      while(className != "" && !found) {
        mem = (*classTable)[className].members;
        if(mem->find(name) != mem->end()) {
          if((*mem)[name].type.baseType != bt_object) {
            typeError(not_object);
          }
          found = true;
          refClass = className;
          break;
        }  
        className = (*classTable)[className].superClassName;
      }
    }
       
    if(found == false) {
      typeError(undefined_variable);
    }

    while(refClass != "" && !memfound) {
      mem = (*classTable)[refClass].members;
      obj = node->identifier_2->name;
      if(mem->find(obj) != mem->end()) {
        memfound = true;
        node->basetype = (*mem)[obj].type.baseType;
        node->objectClassName = (*mem)[obj].type.objectClassName;
        break;
      }
      refClass = (*classTable)[refClass].superClassName;
    }
       
    if(memfound == false) {
      typeError(undefined_member);
    }
    
  }

  if(node->basetype != node->expression->basetype) {
    typeError(assignment_type_mismatch);
  }
}

void TypeCheck::visitCallNode(CallNode* node) {
  node->visit_children(this);
  node->basetype = node->methodcall->basetype; 
}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
  node->visit_children(this);
  
  if(node->expression->basetype != bt_boolean) {
    typeError(if_predicate_type_mismatch);
  }
  
  node->basetype = bt_boolean;
}

void TypeCheck::visitWhileNode(WhileNode* node) {
  // WRITEME: Replace with code if necessary
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean) {
    typeError(while_predicate_type_mismatch);
  }
  
  node->basetype = bt_boolean;
}

void TypeCheck::visitRepeatNode(RepeatNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean) {
    typeError(repeat_predicate_type_mismatch);
  }
}

void TypeCheck::visitPrintNode(PrintNode* node) {
  node->visit_children(this);
  node->basetype = node->expression->basetype;
  node->objectClassName = node->expression->objectClassName;
}

void TypeCheck::visitPlusNode(PlusNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
}

void TypeCheck::visitMinusNode(MinusNode* node) {
  node->visit_children(this);  
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer; 
}

void TypeCheck::visitTimesNode(TimesNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
}

void TypeCheck::visitDivideNode(DivideNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
}

void TypeCheck::visitLessNode(LessNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  
  node->basetype = bt_boolean;
}

void TypeCheck::visitLessEqualNode(LessEqualNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  
  node->basetype = bt_boolean;
}

void TypeCheck::visitEqualNode(EqualNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype == bt_integer) {
    if(node->expression_2->basetype != bt_integer) {
      typeError(expression_type_mismatch);
    }
  }
  else if(node->expression_1->basetype == bt_boolean) {
    if(node->expression_2->basetype != bt_boolean) {
      typeError(expression_type_mismatch);
    }
  }
  else {
    typeError(expression_type_mismatch);
  }

  node->basetype = bt_boolean;
}

void TypeCheck::visitAndNode(AndNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_boolean || node->expression_2->basetype != bt_boolean) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
}

void TypeCheck::visitOrNode(OrNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_boolean || node->expression_2->basetype != bt_boolean) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
}

void TypeCheck::visitNotNode(NotNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
}

void TypeCheck::visitNegationNode(NegationNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_integer) {
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
}

void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
  node->visit_children(this);
  bool found;
  bool methodfound; 
  std::string className;
  std::string refClass;
  if(node->identifier_2 == NULL) {
    if((*currentMethodTable).find(node->identifier_1->name) != (*currentMethodTable).end()) {
      node->basetype = (*currentMethodTable)[node->identifier_1->name].returnType.baseType;
      node->objectClassName =  (*currentMethodTable)[node->identifier_1->name].returnType.objectClassName;

      if((*(*currentMethodTable)[node->identifier_1->name].parameters).size() != node->expression_list->size()) {
        typeError(argument_number_mismatch);
      }

      std::list<CompoundType>::iterator p=(*currentMethodTable)[node->identifier_1->name].parameters->begin();
      for (std::list<ExpressionNode*>::iterator e=node->expression_list->begin(); e != node->expression_list->end(); ++p, ++e) {
        if((*p).baseType != (*e)->basetype){
          typeError(argument_type_mismatch);
        }
      }
    }
    else {
      found = false;
      className = this->currentClassName;
      while(className != "" && !found) {
        if((*(*classTable)[className].methods).find(node->identifier_1->name) != (*(*classTable)[className].methods).end()) {
          found = true;
          node->basetype = (*(*classTable)[className].methods)[node->identifier_1->name].returnType.baseType;
          node->objectClassName =  (*(*classTable)[className].methods)[node->identifier_1->name].returnType.objectClassName;
          refClass = className;
          break;
        }  
        className = (*classTable)[className].superClassName;
      }

      if(found == false) {
        typeError(undefined_method);
      }

      if((*(*(*classTable)[refClass].methods)[node->identifier_1->name].parameters).size() != node->expression_list->size()) {
        typeError(argument_number_mismatch);
      }

      std::list<CompoundType>::iterator p=(*(*classTable)[refClass].methods)[node->identifier_1->name].parameters->begin();
      for (std::list<ExpressionNode*>::iterator e=node->expression_list->begin(); e != node->expression_list->end(); ++p, ++e) {
        if((*p).baseType != (*e)->basetype){
          typeError(argument_type_mismatch);
        }
      }
    }
  }
  else {
    found = false;
    methodfound = false;

    if((*currentVariableTable).find(node->identifier_1->name) != (*currentVariableTable).end()) {
      className= (*currentVariableTable)[node->identifier_1->name].type.objectClassName;
      found = true;
      refClass = className;
      if((*currentVariableTable)[node->identifier_1->name].type.baseType != bt_object) {
        typeError(not_object);
      }
    }
    else {
      className = this->currentClassName;
      while(className != "" && !found) {
        if((*(*classTable)[className].members).find(node->identifier_1->name) != (*(*classTable)[className].members).end()) {
          if((*(*classTable)[className].members)[node->identifier_1->name].type.baseType != bt_object) {
            typeError(not_object);
          }
          found = true;
          refClass = (*(*classTable)[className].members)[node->identifier_1->name].type.objectClassName;
          break;
        }  
        className = (*classTable)[className].superClassName;
      }
    }
       
    if(found == false) {
      typeError(undefined_variable);
    }
    
    while(refClass != "" && !methodfound) {
      if((*(*classTable)[refClass].methods).find(node->identifier_2->name) != (*(*classTable)[refClass].methods).end()) {
        node->basetype = (*(*classTable)[refClass].methods)[node->identifier_2->name].returnType.baseType;
        node->objectClassName = (*(*classTable)[refClass].methods)[node->identifier_2->name].returnType.objectClassName;
        methodfound = true;
        break;
      }
      refClass = (*classTable)[refClass].superClassName;
    }
       
    if(methodfound == false) {
      typeError(undefined_method);
    }
    
    if((*(*(*classTable)[refClass].methods)[node->identifier_2->name].parameters).size() != node->expression_list->size()) {
      typeError(argument_number_mismatch);
    }
    std::list<CompoundType>::iterator p=(*(*classTable)[refClass].methods)[node->identifier_2->name].parameters->begin();
    for (std::list<ExpressionNode*>::iterator e=node->expression_list->begin(); e != node->expression_list->end(); ++p, ++e) {
      if((*p).baseType != (*e)->basetype){
        typeError(argument_type_mismatch);
      }
    }
  }
}

void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
  node->visit_children(this); 
  std::string className;
  std::string refClass;
  bool found = false;
  bool memfound = false;
    
  if((*currentVariableTable).find(node->identifier_1->name) != (*currentVariableTable).end()) {
    className= (*currentVariableTable)[node->identifier_1->name].type.objectClassName;
    found = true;
    refClass = className;
    if((*currentVariableTable)[node->identifier_1->name].type.baseType != bt_object) {
      typeError(not_object);
    }
  }
  else {
    className = this->currentClassName;
    while(className != "" && !found) {
      if((*(*classTable)[className].members).find(node->identifier_1->name) != (*(*classTable)[className].members).end()) {
        if((*(*classTable)[className].members)[node->identifier_1->name].type.baseType != bt_object) {
          typeError(not_object);
        }
        found = true;
        refClass = (*(*classTable)[className].members)[node->identifier_1->name].type.objectClassName;
        break;
      }  
      className = (*classTable)[className].superClassName;

    }  
  }
   
  if(found == false){
    typeError(undefined_variable);
  }
     
  while(refClass != "" && !memfound) {

    if((*(*classTable)[refClass].members).find(node->identifier_2->name) != (*(*classTable)[refClass].members).end()) {
      node->basetype = (*(*classTable)[refClass].members)[node->identifier_2->name].type.baseType;
      node->objectClassName = (*(*classTable)[refClass].members)[node->identifier_2->name].type.objectClassName;
      memfound = true;
      break;
    }
    refClass = (*classTable)[refClass].superClassName;
  }

  if(memfound == false) {
    typeError(undefined_member);
  }
}

void TypeCheck::visitVariableNode(VariableNode* node) {
  node->visit_children(this);
  
  if((*currentVariableTable).find(node->identifier->name) != (*currentVariableTable).end()) {
    node->basetype = (*currentVariableTable)[node->identifier->name].type.baseType;
    if(node->basetype == bt_object){
      node->objectClassName = (*currentVariableTable)[node->identifier->name].type.objectClassName;
    }
  } 
  else{
    bool found = false;
    std::string className = this->currentClassName;
      
    while((className != "") && (!found)){
      if((*(*classTable)[className].members).find(node->identifier->name) != (*(*classTable)[className].members).end()) {
        node->basetype = (*(*classTable)[className].members)[node->identifier->name].type.baseType;
        if(node->basetype == bt_object) {
          node->objectClassName = (*(*classTable)[className].members)[node->identifier->name].type.objectClassName;
        }
        found = true;
        break;
      }
      className = (*classTable)[className].superClassName;
    }
      
    if(!found){
      typeError(undefined_variable);
    }   
  }
}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
  node->basetype = bt_integer;
  node->visit_children(this);
}

void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
  node->basetype = bt_boolean;
  node->visit_children(this);
}

void TypeCheck::visitNewNode(NewNode* node) {
  node->visit_children(this);
  if((*classTable).find(node->identifier->name) == (*classTable).end()) {
    typeError(undefined_class);
  }  
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;
}

void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
  node->basetype = bt_integer;
  node->visit_children(this);
}

void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
  node->basetype = bt_boolean;
  node->visit_children(this);
}

void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;
  node->visit_children(this);
}

void TypeCheck::visitNoneNode(NoneNode* node) {
  node->basetype = bt_none;
  node->visit_children(this);
}

void TypeCheck::visitIdentifierNode(IdentifierNode* node) {
  node->visit_children(this);
}

void TypeCheck::visitIntegerNode(IntegerNode* node) {
  node->basetype = bt_integer;
  node->visit_children(this);
}


// The following functions are used to print the Symbol Table.
// They do not need to be modified at all.

std::string genIndent(int indent) {
  std::string string = std::string("");
  for (int i = 0; i < indent; i++)
    string += std::string(" ");
  return string;
}

std::string string(CompoundType type) {
  switch (type.baseType) {
    case bt_integer:
      return std::string("Integer");
    case bt_boolean:
      return std::string("Boolean");
    case bt_none:
      return std::string("None");
    case bt_object:
      return std::string("Object(") + type.objectClassName + std::string(")");
    default:
      return std::string("");
  }
}


void print(VariableTable variableTable, int indent) {
  std::cout << genIndent(indent) << "VariableTable {";
  if (variableTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (VariableTable::iterator it = variableTable.begin(); it != variableTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << string(it->second.type);
    std::cout << ", " << it->second.offset << ", " << it->second.size << "}";
    if (it != --variableTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}

void print(MethodTable methodTable, int indent) {
  std::cout << genIndent(indent) << "MethodTable {";
  if (methodTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (MethodTable::iterator it = methodTable.begin(); it != methodTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    std::cout << genIndent(indent + 4) << string(it->second.returnType) << "," << std::endl;
    std::cout << genIndent(indent + 4) << it->second.localsSize << "," << std::endl;
    print(*it->second.variables, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --methodTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}

void print(ClassTable classTable, int indent) {
  std::cout << genIndent(indent) << "ClassTable {" << std::endl;
  for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    if (it->second.superClassName != "")
      std::cout << genIndent(indent + 4) << it->second.superClassName << "," << std::endl;
    print(*it->second.members, indent + 4);
    std::cout << "," << std::endl;
    print(*it->second.methods, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --classTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}" << std::endl;
}

void print(ClassTable classTable) {
  print(classTable, 0);
}