#include "typecheck.hpp"

const int METHODRETURNTYPE = 0;
const int DECLARATIONTYPE = 1;

std::list<CompoundType> *currentParameterList;

VariableTable* currentVariableTable_;

CompoundType MethodReturnType;
CompoundType DeclarationType;
int typePhase;
int currentLocalOffset_;
int currentMemberOffset_;
int currentParameterOffset_;

void assignIdentifierValue(std::string s);
void assignTypeValue(TypeNode* node);
VariableInfo* findMemberinSuperClass(std::string identifier, std::string className,ClassTable *classTable);
std::string findSuperClassName(std::string s,ClassTable *classTable);
VariableInfo* searchClassMembersForIdentifier(std::string className, std::string identifier,ClassTable *classTable);
VariableInfo* findMatch(std::string identifier, VariableTable* currentVariableTable_, std::string className, ClassTable *classTable);
VariableInfo* searchVariableTableForIdentifier(std::string identifier, VariableTable *variableTable);
MethodInfo* searchMethodTableForIdentifier(std::string identifier, MethodTable *variableTable);
MethodInfo* searchClassMethodsForIdentifier(std::string className, std::string identifier, ClassTable *classTable);
MethodInfo* findMethodinSuperClass(std::string identifier, std::string className, ClassTable *classTable);
std::string searchTypeForIdentifier(std::string className, std::string identifier, ClassTable *classTable);
std::string findMemberTypeinSuperClass(std::string identifier, std::string className, ClassTable *classTable);

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

void checkMain(ClassTable* classTable){
  ClassInfo* temp = NULL;
  for(auto it : *classTable){
    if(it.first == "Main"){
      temp = &(*classTable)[it.first];
    }
  }
  if(temp==NULL){
    typeError(no_main_class);
  }
  if(temp->members->size()!=0){typeError(main_class_members_present);} 
  if(temp->methods->find("main")==temp->methods->end()){typeError(no_main_method);}


}

void TypeCheck::visitProgramNode(ProgramNode* node) {
  currentVariableTable_ = this->currentVariableTable;
  this->classTable = new ClassTable();
  node->visit_children(this);
  checkMain(classTable);
}

void TypeCheck::visitClassNode(ClassNode* node) {
  MethodTable *methods = new MethodTable();
  VariableTable *variables = new VariableTable();
  currentMethodTable = methods;
  currentVariableTable_ = variables;
  ClassInfo classInfo;
  currentMemberOffset_ = 0;
  currentLocalOffset_ = 0;
  currentClassName = node->identifier_1->name;

  // typePhase = METHODRETURNTYPE;
  // std::cout<<currentVariableTable_->size()<<std::endl;
  if(node->identifier_2==NULL){
    classInfo.superClassName = "";
  }
  else{
    if((*classTable).find(node->identifier_2->name)==(*classTable).end()){typeError(undefined_class);}
    classInfo.superClassName = node->identifier_2->name;
  }
  classInfo.members = variables;
  classInfo.methods = methods;

  classTable->insert(std::pair<std::string,ClassInfo>(currentClassName,classInfo));


  node->visit_children(this);
  (*classTable)[currentClassName].membersSize = variables->size()*4;
  // classInfo.members = variables;
  // classInfo.methods = methods;
  // classInfo.membersSize = variables->size()*4;s
  // ClassTable.erase(currentClassName);
  // ClassTable[currentClassName] = classInfo;
}


void TypeCheck::visitMethodNode(MethodNode* node) {
  MethodInfo methodInfo;
  CompoundType compoundType;
  currentVariableTable_ = new VariableTable();
  currentParameterList = new std::list<CompoundType>();

  currentLocalOffset_ = -4;
  currentParameterOffset_ = 12;
  // typePhase = METHODRETURNTYPE;

  node->visit_children(this);

  compoundType.baseType = node->type->basetype;
  compoundType.objectClassName = node->type->objectClassName;
  methodInfo.returnType = compoundType;

  methodInfo.parameters = currentParameterList;
  methodInfo.variables = currentVariableTable_;
  methodInfo.localsSize = currentLocalOffset_*(-1)-4;
  (*currentMethodTable)[node->identifier->name] = methodInfo;
}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node){
  // typePhase = DECLARATIONTYPE;
  node->visit_children(this);
  // typePhase = METHODRETURNTYPE;
}

void TypeCheck::visitParameterNode(ParameterNode* node) {
  CompoundType compoundType; 
  VariableInfo variableInfo;

  node->visit_children(this);

  // node->basetype = node->type->typebasetype;
  compoundType.baseType = node->type->basetype;
  compoundType.objectClassName = node->type->objectClassName;
  currentParameterList->push_back(compoundType);

  variableInfo.type = compoundType;
  variableInfo.offset = currentParameterOffset_;
  variableInfo.size = 4;
  currentParameterOffset_ += 4;

  currentVariableTable_->insert(std::pair<std::string,VariableInfo>(node->identifier->name,variableInfo));
}

void TypeCheck::visitDeclarationNode(DeclarationNode* node) {
  typePhase = DECLARATIONTYPE;
  node->visit_children(this);
  typePhase = METHODRETURNTYPE;
  // node->basetype=node->type->basetype;
}

void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
  // node->visit_children(this);
  // node->basetype = node->xpression->basetype;
}

void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
  node->visit_children(this);
}

void TypeCheck::visitCallNode(CallNode* node) {
  node->visit_children(this);
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
  node->visit_children(this);
  // if(node->expression->basetype != bt_boolean){
  //   typeError(if_predicate_type_mismatch);
  // }
  // node->basetype = bt_boolean;
}

void TypeCheck::visitWhileNode(WhileNode* node) {
  node->visit_children(this);


}

void TypeCheck::visitRepeatNode(RepeatNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean){
    typeError(repeat_predicate_type_mismatch);
  }
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitPrintNode(PrintNode* node) {
  node->visit_children(this);
  node->basetype = node->expression->basetype;
  node->objectClassName = node->expression->objectClassName;
}

void TypeCheck::visitPlusNode(PlusNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer ||node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitMinusNode(MinusNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer ||node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
}

void TypeCheck::visitTimesNode(TimesNode* node) {
  // std::cout<<"check"<<std::endl;
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer ||node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitDivideNode(DivideNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer ||node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitLessNode(LessNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer ||node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitLessEqualNode(LessEqualNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer ||node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitEqualNode(EqualNode* node) {
  node->visit_children(this);
  if(!(node->expression_1->basetype == bt_integer && node->expression_2->basetype == bt_integer) && !(node->expression_1->basetype == bt_boolean && node->expression_2->basetype == bt_boolean)){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitAndNode(AndNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_boolean ||node->expression_2->basetype != bt_boolean){
    // std::cout<<"Chekc"<<std::endl;
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitOrNode(OrNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_boolean ||node->expression_2->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitNotNode(NotNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitNegationNode(NegationNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  node->basetype = bt_integer;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
  node->visit_children(this);
  std::string methodName;
  std::string className;
  std::list<CompoundType> *parameters;
  MethodInfo* tempmi;

  // std::cout<<node->identifier_1->name<<"gagagagagagagagagagaga"<<std::endl;
  // methodName = node->identifier_1;
  if(node->identifier_2==NULL){
    methodName = node->identifier_1->name;
    tempmi = searchMethodTableForIdentifier(methodName, currentMethodTable);
    if(tempmi==NULL){
      tempmi = findMethodinSuperClass(methodName,currentClassName,classTable);
      if(tempmi==NULL){typeError(undefined_method);}
    }

  }
  else{
    methodName = node->identifier_2->name;
    // std::cout<<methodName<<"methodname"<<std::endl;
    // className = (*currentVariableTable_)[node->identifier_1->name].type->objectClassName;
    if((*currentVariableTable_).find(node->identifier_1->name) != (*currentVariableTable_).end()){
      className = (*currentVariableTable_)[node->identifier_1->name].type.objectClassName;
    }
    else if((*(*classTable)[currentClassName].members).find(node->identifier_1->name) != (*(*classTable)[currentClassName].members).end()){
      className = (*(*classTable)[currentClassName].members)[node->identifier_1->name].type.objectClassName;
    }
    else{
      className = findMemberTypeinSuperClass(node->identifier_1->name, currentClassName, classTable);
    }
    // std::cout<<className<<"className"<<std::endl;
    if(className == ""){typeError(not_object);}
    if((*(*classTable)[className].methods).find(methodName) == (*(*classTable)[className].methods).end()) {
      if(findMethodinSuperClass(methodName,className, classTable)==NULL){
        typeError(undefined_method);
      }
      tempmi = findMethodinSuperClass(methodName,className, classTable);
    }
    else{
      tempmi = &((*(*classTable)[className].methods)[methodName]);
    }
  }

  parameters = tempmi->parameters;
  if(parameters->size()!=node->expression_list->size()){typeError(argument_number_mismatch);}

}



void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
  node->visit_children(this);
  std::string identifierName = node->identifier_2->name;
  std::string className;
  VariableInfo *tempmi;
  if((*currentVariableTable_).find(node->identifier_1->name) != (*currentVariableTable_).end()){
    className = (*currentVariableTable_)[node->identifier_1->name].type.objectClassName;
  }
  else if((*(*classTable)[currentClassName].members).find(node->identifier_1->name) != (*(*classTable)[currentClassName].members).end()){
    className = (*(*classTable)[currentClassName].members)[node->identifier_1->name].type.objectClassName;
  }
  else{
    className = findMemberTypeinSuperClass(node->identifier_1->name, currentClassName, classTable);
  }

  if((*(*classTable)[className].members).find(identifierName) == (*(*classTable)[className].members).end()) {
    tempmi = findMemberinSuperClass(identifierName,className, classTable);
  }
  else{
    tempmi = &((*(*classTable)[className].members)[identifierName]);
  }

  node->basetype = tempmi->type.baseType;

}

void TypeCheck::visitVariableNode(VariableNode* node) {
  node->visit_children(this);
  // std::cout<<node->identifier->name<<std::endl;
  VariableInfo* vi = findMatch(node->identifier->name, currentVariableTable_, currentClassName, classTable);
  if(vi == NULL){
    typeError(undefined_variable);
  }

  node->basetype = vi->type.baseType;
}

VariableInfo* findMatch(std::string identifier, VariableTable* currentVariableTable_, std::string className, ClassTable *classTable){
  if(searchVariableTableForIdentifier(identifier,currentVariableTable_)){return searchVariableTableForIdentifier(identifier,currentVariableTable_);}
  if(searchClassMembersForIdentifier(className, identifier, classTable)){return searchClassMembersForIdentifier(className, identifier, classTable);}
  if(findMemberinSuperClass(identifier, className, classTable)){return findMemberinSuperClass(identifier, className, classTable);}
  return NULL;
}

MethodInfo* findMethodinSuperClass(std::string identifier, std::string className, ClassTable *classTable){
  std::string nextClass = findSuperClassName(className,classTable);
  if(nextClass == ""){
    return NULL;
  }
  MethodInfo* temp = searchClassMethodsForIdentifier(nextClass, identifier, classTable);

  if(temp==NULL){
    return findMethodinSuperClass(identifier, nextClass, classTable);
  }
  return temp;

}

std::string findMemberTypeinSuperClass(std::string identifier, std::string className, ClassTable *classTable){
  std::string nextClass = findSuperClassName(className,classTable);
  std::string currentResult = searchTypeForIdentifier(nextClass, identifier, classTable);

  if(currentResult == ""){
    return findMemberTypeinSuperClass(identifier, nextClass, classTable);
  }
  return currentResult;
}

VariableInfo* findMemberinSuperClass(std::string identifier, std::string className, ClassTable *classTable){
  std::string nextClass = findSuperClassName(className,classTable);
  VariableInfo* temp;
  if(nextClass == ""){
    return NULL;
  }
  temp = searchClassMembersForIdentifier(nextClass, identifier, classTable);
  if(temp==NULL){
    return findMemberinSuperClass(identifier, nextClass, classTable);
  }
  return temp;
}

std::string findSuperClassName(std::string s, ClassTable *classTable){
  for(auto it : *classTable){
    if(it.first == s && it.second.superClassName != ""){
      return it.second.superClassName;
    }
  }
  return "";
}

std::string searchTypeForIdentifier(std::string className, std::string identifier, ClassTable *classTable){
  // std::cout<<(*(*classTable)[className].members).size()<<std::endl;
  for(auto it : (*(*classTable)[className].members)){
    if(it.first == identifier){
      return it.second.type.objectClassName;
    }
  }
  return "";
}

MethodInfo* searchClassMethodsForIdentifier(std::string className, std::string identifier, ClassTable *classTable){
  // std::cout<<(*(*classTable)[className].members).size()<<std::endl;
  for(auto it : (*(*classTable)[className].methods)){
    if(it.first == identifier){
      return &(*(*classTable)[className].methods)[it.first];
    }
  }
  return NULL;
}

VariableInfo* searchClassMembersForIdentifier(std::string className, std::string identifier, ClassTable *classTable){
  // std::cout<<(*(*classTable)[className].members).size()<<std::endl;
  for(auto it : (*(*classTable)[className].members)){
    if(it.first == identifier){
      return &((*(*classTable)[className].members)[it.first]);
    }
  }
  return NULL;
}

MethodInfo* searchMethodTableForIdentifier(std::string identifier, MethodTable *variableTable){
  for(auto it : *variableTable){
    if(it.first == identifier){
      return &((*variableTable)[it.first]);
    }
  }
  return NULL;
}

VariableInfo* searchVariableTableForIdentifier(std::string identifier, VariableTable *variableTable){
  for(auto it : *variableTable){
    if(it.first == identifier){
      return &((*variableTable)[it.first]);
    }
  }
  return NULL;
}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
  node->visit_children(this);
  node->basetype = bt_integer;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
  node->visit_children(this);
  node->basetype = bt_boolean;
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitNewNode(NewNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
  node->visit_children(this);
  node->basetype = bt_integer;
  node->objectClassName = "";
  assignTypeValue(node);
}

void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
  node->visit_children(this);
  node->basetype = bt_boolean;
  node->objectClassName = "";
  assignTypeValue(node);
}

void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
  // node->visit_children(this);
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;
  assignTypeValue(node);
}

void TypeCheck::visitNoneNode(NoneNode* node) {
  node->visit_children(this);
  node->basetype = bt_none;
  node->objectClassName = "";
}

void TypeCheck::visitIdentifierNode(IdentifierNode* node) {
  node->visit_children(this);
  assignIdentifierValue(node->name);
}

void TypeCheck::visitIntegerNode(IntegerNode* node) {
  // WRITEME: Replace with code if necessary
}

void assignIdentifierValue(std::string s){
  // std::cout<<s<<std::endl;
  switch(typePhase){
    case DECLARATIONTYPE:
      {
        VariableInfo variableInfo;
        variableInfo.type = DeclarationType;
        if(currentLocalOffset_==0){
          variableInfo.offset = currentMemberOffset_;
          currentMemberOffset_ = currentMemberOffset_ + 4;
        }
        else{
          variableInfo.offset = currentLocalOffset_;
          currentLocalOffset_ = currentLocalOffset_ - 4;
        }

        variableInfo.size = 4;
        (*currentVariableTable_)[s] = variableInfo;
        break;
      }
    default:
      break;
  }
}

void assignTypeValue(TypeNode* node){
  switch(typePhase){
    case DECLARATIONTYPE:
      {
        CompoundType compoundType;
        compoundType.baseType = node->basetype;
        compoundType.objectClassName = node->objectClassName;
        DeclarationType = compoundType;
        break;
      }
      // (*currentVariableTable)[]
    default:
      break;
  }
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
