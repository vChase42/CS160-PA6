#include "typecheck.hpp"
#include <iostream>


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
    case do_while_predicate_type_mismatch:
      std::cerr << "Predicate of do while loop is not boolean." << std::endl;
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
  // WRITEME: Replace with code if necessary
  currentLocalOffset = -4;
  currentParameterOffset = 12;
  

  classTable = new ClassTable();
  
  node->visit_children(this);

  if(classTable->count("Main") == 0) typeError(no_main_class);


}

void TypeCheck::visitClassNode(ClassNode* node) {
  // WRITEME: Replace with code if necessary

  ClassInfo z;
  currentClassName = node->identifier_1->name;
  if(node->identifier_2){
    if(classTable->count(node->identifier_2->name) == 0) typeError(undefined_class);
    z.superClassName = node->identifier_2->name;
  }else{
    z.superClassName = "";
  }


  
  z.methods = new MethodTable();
  z.members = new VariableTable();
  currentMethodTable = z.methods;
  currentVariableTable = z.members;

  (*classTable)[node->identifier_1->name] = z;
  
  
  node->visit_children(this);
  //figure out declaration list here???

  currentMemberOffset = 0;
  if(node->declaration_list){
  for(auto x: *(node->declaration_list)){
    if(x->identifier_list){
    for(auto y: *(x->identifier_list)){
      (*(*classTable)[currentClassName].members)[y->name].offset = currentMemberOffset;
      currentMemberOffset += 4;
    }}
  }}

  (*classTable)[currentClassName].membersSize = (*classTable)[currentClassName].members->size();
  
  if(currentClassName == "Main"){
    //no members allowed
    if((*classTable)[currentClassName].membersSize > 0) typeError(main_class_members_present);
    //must contain main method
    if((*classTable)[currentClassName].methods->count("main") == 0) typeError(no_main_method);
    //main must not have return or parameters
    if((*(*classTable)[currentClassName].methods)["main"].returnType.baseType != bt_none) typeError(main_method_incorrect_signature);
    if((*(*classTable)[currentClassName].methods)["main"].parameters->size() != 0) typeError(main_method_incorrect_signature);
  }

  //check that constructor type has no arguments
  if((*classTable)[currentClassName].methods->count(currentClassName) != 0){
    if((*(*classTable)[currentClassName].methods)[currentClassName].returnType.baseType != bt_none) typeError(constructor_returns_type);
  }


}

void TypeCheck::visitMethodNode(MethodNode* node) {
  // WRITEME: Replace with code if necessary
  MethodInfo m;
  m.variables = new VariableTable();
  currentVariableTable = m.variables;
  m.parameters = new std::list<CompoundType>();
  

  m.returnType.baseType = node->type->basetype;
  if(m.returnType.baseType == bt_object){
    m.returnType.objectClassName = node->type->objectClassName;
  }

  currentParameterOffset = 12;
  currentLocalOffset = -4;
  node->visit_children(this);

  for(auto x: *(node->parameter_list)){
    CompoundType t;
    t.baseType = x->basetype;
    t.objectClassName = x->objectClassName;
    m.parameters->push_back(t);
  }

  m.localsSize = m.variables->size()*4 - m.parameters->size()*4;     //include calculation for parameters too?   change the offset value too?

  (*currentMethodTable)[node->identifier->name] = m;


  //TYPE CHECKING FOR RETURN STATEMENT
  if(node->type->basetype == bt_object){
    if(node->methodbody == NULL) typeError(return_type_mismatch);
    if(node->methodbody->returnstatement == NULL) typeError(return_type_mismatch);
    if(node->type->basetype != node->methodbody->returnstatement->basetype || node->type->objectClassName != node->methodbody->returnstatement->objectClassName) typeError(return_type_mismatch);
  }else if(node->type->basetype != bt_none){
    if(node->methodbody == NULL) typeError(return_type_mismatch);
    if(node->methodbody->returnstatement == NULL) typeError(return_type_mismatch);
    if(node->type->basetype != node->methodbody->returnstatement->basetype) typeError(return_type_mismatch);
  }else if(node->type->basetype == bt_none){
    if(node->methodbody){
      if(node->methodbody->returnstatement) typeError(return_type_mismatch);
    }
  }
}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); 


    currentLocalOffset = -4;
    if(node->declaration_list){
    for(auto x: *(node->declaration_list)){
      if(x->identifier_list){
      for(auto y: *(x->identifier_list)){
        (*currentVariableTable)[y->name].offset = currentLocalOffset;
        currentLocalOffset -= 4;
      }}
    }}

}

void TypeCheck::visitParameterNode(ParameterNode* node) {
  // WRITEME: Replace with code if necessary
  
  node->basetype = node->type->basetype;
  if(node->basetype == bt_object){
    node->objectClassName = node->type->objectClassName;
  }

  VariableInfo v;
  v.type.baseType = node->type->basetype;
  if(v.type.baseType == bt_object){
    v.type.objectClassName = node->type->objectClassName;
    //OBJ_SIZE - v.size
  }
  v.offset = currentParameterOffset;
  v.size = 4;
  currentParameterOffset += 4;

  (*currentVariableTable)[node->identifier->name] = v;
}



void TypeCheck::visitDeclarationNode(DeclarationNode* node) {
  // WRITEME: Replace with code if necessary
  // node->visit_children(this);   //WILL NEED TO UNCOMMENT THIS IF WE WANT TO SET BT INFO THROUGH VISITS

  node->basetype = node->type->basetype;
  node->objectClassName = node->type->objectClassName; 
  
  if(node->basetype == bt_object){
    if(classTable->count(node->objectClassName) == 0) typeError(undefined_class);
  }


  CompoundType t;
  t.baseType = node->basetype;
  t.objectClassName = node->objectClassName;

  for(auto x: *(node->identifier_list)){
    VariableInfo v;
    v.type = t;
    v.size = 4;
    (*currentVariableTable)[x->name] = v;
  }


}

void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this);
  //figure out how to see the method returntype and connect it here. 

  node->basetype = node->expression->basetype;
  node->objectClassName = node->expression->objectClassName;

}

void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this);  //CHECK IF EXPRESSION IS CORRECT TYPE
  
  //check variablenames exist
  std::string className = currentClassName;

  std::string OBJECTName;
  std::string memberName;
  CompoundType id_1;

  if(node->identifier_2){
    OBJECTName = node->identifier_1->name;
    memberName = node->identifier_2->name;

    //check variable table or member table for objectName
    if(currentVariableTable->count(OBJECTName) == 1){
      if((*currentVariableTable)[OBJECTName].type.baseType != bt_object) typeError(not_object);
      className = (*currentVariableTable)[OBJECTName].type.objectClassName;
    }else if((*classTable)[currentClassName].members->count(OBJECTName) == 1){
      if((*(*classTable)[currentClassName].members)[OBJECTName].type.baseType != bt_object) typeError(not_object);
      className = (*(*classTable)[currentClassName].members)[OBJECTName].type.objectClassName;
    }else{
      std::string superClassName = (*classTable)[currentClassName].superClassName;
      bool success = false;
      while(superClassName != ""){
          if((*classTable)[superClassName].members->count(OBJECTName) == 0){
            superClassName = (*classTable)[superClassName].superClassName;
          }else{
            if((*(*classTable)[superClassName].members)[OBJECTName].type.baseType != bt_object) typeError(not_object);
            success = true;
            className = superClassName;
            break;
          }
        }
        if(success == false){
          typeError(undefined_member);
      }
      typeError(undefined_variable);
    }


    if(classTable->count(className) == 0) typeError(undefined_class);
    if((*classTable)[className].members->count(memberName) == 0){
      //check superclasses
      if((*classTable)[className].superClassName != ""){
        bool success = false;
        std::string superClassName = (*classTable)[className].superClassName;
        while(superClassName != ""){
          if((*classTable)[superClassName].members->count(memberName) == 0){
            superClassName = (*classTable)[superClassName].superClassName;
          }else{
            success = true;
            break;
          }
        }
        if(success == false){
          typeError(undefined_member);
        }
        className = superClassName;
      }else{
        typeError(undefined_member);
      }
    } 
    
    id_1 = (*(*classTable)[className].members)[memberName].type;
    
  }else{
    memberName = node->identifier_1->name;
    if(currentVariableTable->count(memberName) == 0){
      if((*classTable)[currentClassName].members->count(memberName) == 0) typeError(undefined_variable);
      id_1 = (*(*classTable)[currentClassName].members)[memberName].type;
    }else{
      id_1 = (*currentVariableTable)[memberName].type;
    }
  }
  //check types
    
  if(id_1.baseType == bt_object){
    if(node->expression->basetype != bt_object || id_1.objectClassName != node->expression->objectClassName) typeError(assignment_type_mismatch);
  }else if(id_1.baseType != node->expression->basetype){
    typeError(assignment_type_mismatch);
  }

}

void TypeCheck::visitCallNode(CallNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //get type from children.
  node->basetype = node->methodcall->basetype;
  node->objectClassName = node->methodcall->objectClassName;

}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check expression is bool. thats it?

  if(node->expression->basetype != bt_boolean) typeError(if_predicate_type_mismatch);
  
}

void TypeCheck::visitWhileNode(WhileNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check experssion is bool
  if(node->expression->basetype != bt_boolean) typeError(while_predicate_type_mismatch);


}

void TypeCheck::visitDoWhileNode(DoWhileNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check expression is bool
  if(node->expression->basetype != bt_boolean) typeError(do_while_predicate_type_mismatch);

}

void TypeCheck::visitPrintNode(PrintNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //i think this is legal no matter what.
}

void TypeCheck::visitPlusNode(PlusNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are ints
  node->basetype = bt_integer;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_integer) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_integer) typeError(expression_type_mismatch);


}

void TypeCheck::visitMinusNode(MinusNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are ints
  node->basetype = bt_integer;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_integer) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_integer) typeError(expression_type_mismatch);

}

void TypeCheck::visitTimesNode(TimesNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are ints
  node->basetype = bt_integer;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_integer) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_integer) typeError(expression_type_mismatch);

}

void TypeCheck::visitDivideNode(DivideNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are ints
  node->basetype = bt_integer;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_integer) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_integer) typeError(expression_type_mismatch);

}

void TypeCheck::visitGreaterNode(GreaterNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are ints, set current type to bool
  node->basetype = bt_boolean;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_integer) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_integer) typeError(expression_type_mismatch);

}

void TypeCheck::visitGreaterEqualNode(GreaterEqualNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are ints, set current type to bool
  node->basetype = bt_boolean;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_integer) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_integer) typeError(expression_type_mismatch);


}

void TypeCheck::visitEqualNode(EqualNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressions are either BOTH INT or BOTH BOOL.result is bool
  node->basetype = bt_boolean;
  node->objectClassName = "";
  BaseType e_1 = node->expression_1->basetype;
  BaseType e_2 = node->expression_2->basetype;
  
  if(e_1 == bt_integer){
    if(e_2 != bt_integer) typeError(expression_type_mismatch);
  }else if(e_1 == bt_boolean){
    if(e_2 != bt_boolean) typeError(expression_type_mismatch);
  }else{
    typeError(expression_type_mismatch);
  }
}

void TypeCheck::visitAndNode(AndNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressionsa are bool. result is bool
  node->basetype = bt_boolean;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_boolean) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_boolean) typeError(expression_type_mismatch);

}

void TypeCheck::visitOrNode(OrNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if both expressionsa are bool. result is bool
  node->basetype = bt_boolean;
  node->objectClassName = "";
  if(node->expression_1->basetype != bt_boolean) typeError(expression_type_mismatch);
  if(node->expression_2->basetype != bt_boolean) typeError(expression_type_mismatch);
}

void TypeCheck::visitNotNode(NotNode* node) {
  // WRITEME: Replace with code if necessary
  node->visit_children(this); //check if both expressions are bool. result is bool
  node->basetype = bt_boolean;
  node->objectClassName = "";
  if(node->expression->basetype != bt_boolean) typeError(expression_type_mismatch);

}

void TypeCheck::visitNegationNode(NegationNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if expression is int
  node->basetype = bt_integer;
  node->objectClassName = "";
  if(node->expression->basetype != bt_integer) typeError(expression_type_mismatch);
  

}

void TypeCheck::visitQMNode(QMNode *node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //check if expression_1 is bool or int? //also check the types? 

  if(node->expression_1->basetype != bt_boolean) typeError(expression_type_mismatch);

  BaseType e_1 = node->expression_2->basetype;
  BaseType e_2 = node->expression_3->basetype;

  if(e_1 == bt_integer){
    if(e_2 != bt_integer) typeError(expression_type_mismatch);
    node->basetype = bt_integer;
  }else if(e_1 == bt_boolean){
    if(e_2 != bt_boolean) typeError(expression_type_mismatch);
    node->basetype = bt_boolean;
  }else{
    typeError(expression_type_mismatch);
  }


}

void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //set type to return type of the method. will have to access method from classtable/methodtable?
  
  //check method exists, or if its a class->method accessor
  //not object error
  //undefined method error
  //argument_numer_mismatch
  //argument type mismatch

  //undefined class too

  std::string methodName;
  MethodInfo m;


  if(node->identifier_2){   //method accessor from variable
    std::string className;
  
    std::string OBJECTName = node->identifier_1->name; //check local vars and member vars for this.
    methodName = node->identifier_2->name;

    if(currentVariableTable->count(OBJECTName) == 1){
      if((*currentVariableTable)[OBJECTName].type.baseType != bt_object) typeError(not_object);
      className = (*currentVariableTable)[OBJECTName].type.objectClassName;
    }else if((*classTable)[currentClassName].members->count(OBJECTName) == 1){
      if((*(*classTable)[currentClassName].members)[OBJECTName].type.baseType != bt_object) typeError(not_object);
      className = (*(*classTable)[currentClassName].members)[OBJECTName].type.objectClassName;
    }else{
      std::string superClassName = (*classTable)[currentClassName].superClassName;
      bool success = false;
      while(superClassName != ""){
          if((*classTable)[superClassName].members->count(OBJECTName) == 0){
            superClassName = (*classTable)[superClassName].superClassName;
          }else{
            if((*(*classTable)[superClassName].members)[OBJECTName].type.baseType != bt_object) typeError(not_object);
            success = true;
            className = superClassName;
            break;
          }
        }
        if(success == false){
          typeError(undefined_member);
      }
      typeError(undefined_variable);
    }



    if((*classTable).count(className) == 0) typeError(undefined_class);
    if((*classTable)[className].methods->count(methodName) == 0){
        //check superclasses
        if((*classTable)[className].superClassName != ""){
          std::string superClassName = (*classTable)[className].superClassName;
          bool success = false;
          while(superClassName != ""){
            if((*classTable)[superClassName].methods->count(methodName) == 0){
              superClassName = (*classTable)[superClassName].superClassName;
            }else{
              success = true;
              break;
            }
          }
          if(success == false){
            typeError(undefined_method);
          }
          className = superClassName;
        }else{
          typeError(undefined_method);
        }
      }
    m = (*(*classTable)[className].methods)[methodName];   // <--- lol...
    node->identifier_1->objectClassName = className;

  }else{   //just a normal method

    methodName = node->identifier_1->name;
    if((*currentMethodTable).count(methodName) == 0){ //method doesnt exists
      typeError(undefined_method);
    }else{ //method exists
      m = (*currentMethodTable)[methodName];
      
    }
  }

  node->basetype = m.returnType.baseType;
  node->objectClassName = m.returnType.objectClassName;

  int numArgs = node->expression_list->size();
  int argsExpected = m.parameters->size();
  if(numArgs == argsExpected){
    //bro why are we using lists this is so not cash money :(((())))
    std::list<ExpressionNode*>::iterator it_1 = node->expression_list->begin();
    std::list<CompoundType>::iterator it_2 = m.parameters->begin();

    for(; it_1 != node->expression_list->end() && it_2 != m.parameters->end(); ++it_1, ++it_2){
      if((*it_2).baseType == bt_object){
        if((*it_1)->basetype != (*it_2).baseType || (*it_1)->objectClassName != (*it_2).objectClassName) typeError(argument_type_mismatch);
      }else{
        if((*it_1)->basetype != (*it_2).baseType) typeError(argument_type_mismatch);
      }
    }
  }else{  //numbers of parameters mismatch
        typeError(argument_number_mismatch);
  }
}


void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //set type to type of that member. will have to access classtable/methodtable/variabletable
  
  //undefined class
  //undefined member

  std::string OBJECTName = node->identifier_1->name;
  std::string memberName = node->identifier_2->name;

  std::string className;
  //check variable table or member table for objectName
  if(currentVariableTable->count(OBJECTName) == 1){
    if((*currentVariableTable)[OBJECTName].type.baseType != bt_object) typeError(not_object);
    className = (*currentVariableTable)[OBJECTName].type.objectClassName;
  }else if((*classTable)[currentClassName].members->count(OBJECTName) == 1){
    if((*(*classTable)[currentClassName].members)[OBJECTName].type.baseType != bt_object) typeError(not_object);
    className = (*(*classTable)[currentClassName].members)[OBJECTName].type.objectClassName;
  }else{
    std::string superClassName = (*classTable)[currentClassName].superClassName;
    bool success = false;
    while(superClassName != ""){
        if((*classTable)[superClassName].members->count(OBJECTName) == 0){
          superClassName = (*classTable)[superClassName].superClassName;
        }else{
          if((*(*classTable)[superClassName].members)[OBJECTName].type.baseType != bt_object) typeError(not_object);
          success = true;
          className = superClassName;
          break;
        }
      }
      if(success == false){
        typeError(undefined_member);
    }
    typeError(undefined_variable);
  }


  if(classTable->count(className) == 0) typeError(undefined_class);
  if((*classTable)[className].members->count(memberName) == 0){
    //check superclasses
    if((*classTable)[className].superClassName != ""){
      bool success = false;
      std::string superClassName = (*classTable)[className].superClassName;
      while(superClassName != ""){
        if((*classTable)[superClassName].members->count(memberName) == 0){
          superClassName = (*classTable)[superClassName].superClassName;
        }else{
          success = true;
          break;
        }
      }
      if(success == false){
        typeError(undefined_member);
      }
      className = superClassName;
    }else{
      typeError(undefined_member);
    }
  } 

  CompoundType t = (*(*classTable)[className].members)[memberName].type;

  node->basetype = t.baseType;
  node->objectClassName = t.objectClassName;
  

}

void TypeCheck::visitVariableNode(VariableNode* node) {
  // WRITEME: Replace with code if necessary

 //set type to that variable. Will have to access local variabletable and class members?
  std::string varName = node->identifier->name;

  std::string className = currentClassName;
  CompoundType t;
  if(currentVariableTable->count(varName) == 0){
    if((*classTable)[currentClassName].members->count(varName) == 0){
    //check superclasses
    if((*classTable)[currentClassName].superClassName != ""){
      bool success = false;
      std::string superClassName = (*classTable)[currentClassName].superClassName;
      while(superClassName != ""){
        if((*classTable)[superClassName].members->count(varName) == 0){
          superClassName = (*classTable)[superClassName].superClassName;
        }else{
          success = true;
          break;
        }
      }
      if(success == false){
        typeError(undefined_variable);
      }
      className = superClassName;
    }else{
      typeError(undefined_variable);
    }
  } 


    
    t = (*(*classTable)[className].members)[varName].type;
  }else{
    t = (*currentVariableTable)[varName].type;
  }



  node->basetype = t.baseType;
  node->objectClassName = t.objectClassName;

}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
  // WRITEME: Replace with code if necessary
  node->basetype = bt_integer;

   //this is an integer type!
}

void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
  // WRITEME: Replace with code if necessary
  //this is a boolean type!
  node->basetype = bt_boolean;

}

void TypeCheck::visitNewNode(NewNode* node) {
  // WRITEME: Replace with code if necessary

  node->visit_children(this); //set type object and set identifier.
  //this is harsh
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;


  //undefined class
  //argument NUM/TYPE mismatch
  
  std::string className = node->identifier->name;

  if(classTable->count(className) == 0) typeError(undefined_class);   //do i need to find a way to get the constructor??? FUCK

  if((*classTable)[className].methods->count(className) == 0){  //no constructor
    if(node->expression_list->size() != 0) typeError(argument_number_mismatch);
  }else{  //yes constructor
    MethodInfo c = (*(*classTable)[className].methods)[className];

    std::list<ExpressionNode*>::iterator it_1 = node->expression_list->begin();
    std::list<CompoundType>::iterator it_2 = c.parameters->begin();

    for(; it_1 != node->expression_list->end() && it_2 != c.parameters->end(); ++it_1, ++it_2){
      if((*it_2).baseType == bt_object){
        if((*it_1)->basetype != (*it_2).baseType || (*it_1)->objectClassName != (*it_2).objectClassName) typeError(argument_type_mismatch);
      }else{
        if((*it_1)->basetype != (*it_2).baseType) typeError(argument_type_mismatch);
      }
    }
  }


}

void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
  // WRITEME: Replace with code if necessary
 //wtf is this, its just an integer.

  node->basetype = bt_integer;

}

void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
  // WRITEME: Replace with code if necessary
 //this is a boolean
  node->basetype = bt_boolean;
}

void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
  // WRITEME: Replace with code if necessary
 //this is an object type node, set type to object and use the identifier
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;
}

void TypeCheck::visitNoneNode(NoneNode* node) {
  // WRITEME: Replace with code if necessary

 //this is none type
  node->basetype = bt_none;

}

void TypeCheck::visitIdentifierNode(IdentifierNode* node) {
  // WRITEME: Replace with code if necessary

  //no type i mean i guess its object type?


}

void TypeCheck::visitIntegerNode(IntegerNode* node) {
  // WRITEME: Replace with code if necessary
  node->basetype = bt_integer;
  //int type
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
