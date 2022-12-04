#include "codegeneration.hpp"

// CodeGenerator Visitor Functions: These are the functions
// you will complete to generate the x86 assembly code. Not
// all functions must have code, many may be left empty.

void CodeGenerator::visitProgramNode(ProgramNode* node) {
    // WRITEME: Replace with code if necessary

    std::cout << ".data" << std::endl;
    std::cout << "printstr: .asciz \"%d\\n\"" << std::endl;
    std::cout << std::endl;
    std::cout << ".text" << std::endl;
    std::cout << ".globl Main_main" << std::endl;

    node->visit_children(this);

    std::cout << "leave" << std::endl;
    // std::cout << "ret" << std::endl;
    //code must exit with leave
}

void CodeGenerator::visitClassNode(ClassNode* node) {
    // WRITEME: Replace with code if necessary

    currentClassName = node->identifier_1->name;
    currentClassInfo = (*classTable)[currentClassName];
    //code to decrement stack register to allocate room for variablenames
    node->visit_children(this);


}

void CodeGenerator::visitMethodNode(MethodNode* node) {
    // WRITEME: Replace with code if necessary

    currentMethodName = node->identifier->name;
    std::cout << currentClassName << "_" <<currentMethodName << ":" << std::endl;

    currentMethodInfo = (*(*classTable)[currentClassName].methods)[currentMethodName];

    // if(currentMethodName != "main"){
        std::cout << "#preamble" << std::endl;
        std::cout << "push %ebp" << std::endl;
        std::cout << "mov %esp, %ebp" << std::endl;
        std::cout << "sub $32, %esp" << std::endl; 
        // %ebx, %esi, and %edi
        std::cout << "push %ebx" << std::endl;
        std::cout << "push %esi" << std::endl;
        std::cout << "push %edi" << std::endl;
    // }

    node->visit_children(this);
    // if(currentMethodName != "main"){
        std::cout << "#prologue" << std::endl;
        std::cout << "pop %edi" << std::endl;
        std::cout << "pop %esi" << std::endl;
        std::cout << "pop %ebx" << std::endl;
        std::cout << "mov %ebp, %esp" << std::endl;
        std::cout << "pop %ebp" << std::endl;
        std::cout << "ret" << std::endl;
    // }


}

void CodeGenerator::visitMethodBodyNode(MethodBodyNode* node) {
    // WRITEME: Replace with code if necessary

    node->visit_children(this);

}

void CodeGenerator::visitParameterNode(ParameterNode* node) {
    // WRITEME: Replace with code if necessary
    
}

void CodeGenerator::visitDeclarationNode(DeclarationNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitReturnStatementNode(ReturnStatementNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression->accept(this);
    std::cout << "pop %eax" << std::endl;
}

void CodeGenerator::visitAssignmentNode(AssignmentNode* node) {
    // WRITEME: Replace with code if necessary
    
    node->expression->accept(this);
    if(node->identifier_2 == NULL){
        //popl %ebx
        //mov %ebx OFFSET(%ebp)
        if(currentMethodInfo.variables->count(node->identifier_1->name)){
            VariableInfo v = (*currentMethodInfo.variables)[node->identifier_1->name];

            std::cout << "pop " << v.offset << "(%ebp)" << std::endl;
        }else{
            VariableInfo v = (*currentClassInfo.members)[node->identifier_1->name];

            std::cout << "mov 8(%ebp), %ebx" << std::endl;
            std::cout << "pop " << v.offset << "(%ebx)" << std::endl;
        }
        

    }else{
        //CODE NEEDED HERE
        std::string var_name = node->identifier_1->name;
        std::string member_name = node->identifier_2->name;

        //get var_table of the class
        //check local vars, and class members
        

        if(currentMethodInfo.variables->count(var_name) != 0){
            VariableInfo v = (*currentMethodInfo.variables)[var_name];
            std::string className = v.type.objectClassName;
            
            VariableInfo target_var = (*(*classTable)[className].members)[member_name];   

            std::cout << "mov " << v.offset << "(%ebp), %ebx" << std::endl;
            std::cout << "pop " << target_var.offset << "(%ebx)" << std::endl;

        }else{
            VariableInfo v = (*currentClassInfo.members)[var_name];
            std::string className = v.type.objectClassName;

            VariableInfo target_var = (*(*classTable)[className].members)[member_name];

            std::cout << "move 8(%ebp), %ebx" << std::endl;
            std::cout << "pop " << target_var.offset << "(%ebx)" << std::endl;


        }


    }

}


/*
REGISTERS:
BASE POINTER
%ebp
Stack Pointer
%esp

SAVE REGISTERS
%eax, %ecx, and %edx

CALLE SAVE REGISTERS: (I THINK THIS MEANS LOCAL VARIABLES)
%ebx, %esi, and %edi

*/



void CodeGenerator::visitCallNode(CallNode* node) {
    // WRITEME: Replace with code if necessary

    node->visit_children(this);

}

void CodeGenerator::visitIfElseNode(IfElseNode* node) {
    // WRITEME: Replace with code if necessary



    if(node->statement_list_2 == NULL){ //no else statement
        node->expression->accept(this);
        std::string l_false = "FALSE_" + std::to_string(nextLabel());

        std::cout << "#IF STATEMENT" << std::endl;
        std::cout << "popl %ebx" << std::endl;
        std::cout << "mov $0, %esi " << std::endl;
        std::cout << "cmp %ebx, %esi" << std::endl;
        std::cout << "JE " + l_false << std::endl;
                for(auto x: (*node->statement_list_1)){
            x->accept(this);
        }
        std::cout << l_false + ":" << std::endl;
        std::cout << "#Done IF statement" << std::endl;
    }else{
        node->expression->accept(this);
        std::string l_false = "FALSE_" + std::to_string(nextLabel());
        std::string l_end = "END_" + std::to_string(nextLabel());

        std::cout << "#IF STATEMENT" << std::endl;
        std::cout << "popl %ebx" << std::endl;
        std::cout << "mov $0, %esi " << std::endl;
        std::cout << "cmp %ebx, %esi" << std::endl;
        std::cout << "JE " + l_false << std::endl;
        for(auto x: (*node->statement_list_1))
            x->accept(this);
        std::cout << "jmp " + l_end << std::endl;
        std::cout << l_false + ":" << std::endl;
        for(auto x:(*node->statement_list_2))
            x->accept(this);
        std::cout << l_end + ":" << std::endl;
        std::cout << "#Done IF statement" << std::endl;
    }

}

void CodeGenerator::visitWhileNode(WhileNode* node) {
    // WRITEME: Replace with code if necessary
    std::string label_loop = "WHILE_" + std::to_string(nextLabel());
    std::string label_end = "WHILE_END_" + std::to_string(nextLabel());
    
    std::cout << label_loop << ":" << std::endl;
    node->expression->accept(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "cmp $1, %ebx" << std::endl;
    std::cout << "jne " << label_end << std::endl;
    for(auto x: (*node->statement_list)){
        x->accept(this);
    }
    std::cout << "jmp " << label_loop << std::endl;
    std::cout << label_end << ":" << std::endl;


}

void CodeGenerator::visitPrintNode(PrintNode* node) {
    // WRITEME: Replace with code if necessary

    node->visit_children(this);

    std::cout << "#PRINT" << std::endl;
    std::cout << "push $printstr" << std::endl;
    std::cout << "call printf" << std::endl;

}

void CodeGenerator::visitDoWhileNode(DoWhileNode* node) {
    // WRITEME: Replace with code if necessary
    std::string label_loop = "DOWHILE_" + std::to_string(nextLabel());
    
    std::cout << label_loop << ":" << std::endl;
    for(auto x: (*node->statement_list)){
        x->accept(this);
    }
    node->expression->accept(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "cmp $1, %ebx" << std::endl;
    std::cout << "je " << label_loop << std::endl;
}

void CodeGenerator::visitQMNode(QMNode* node){
    // WRITEME: Replace with code if necessary
    std::string l_false = "false_" + std::to_string(nextLabel());
    std::string l_end = "end_" + std::to_string(nextLabel());

    node->expression_1->accept(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "mov $0, %esi" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "je " << l_false << std::endl;
    node->expression_2->accept(this);
    std::cout << "jmp " << l_end << std::endl;
    std::cout << l_false << ":" << std::endl;
    node->expression_3->accept(this);
    std::cout << l_end << ":" << std::endl;
}

void CodeGenerator::visitPlusNode(PlusNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);

    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %esi" << std::endl;
    std::cout << "add %esi, %ebx" << std::endl;
    std::cout << "push %ebx" << std::endl;
}

void CodeGenerator::visitMinusNode(MinusNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
    
    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %esi" << std::endl;
    std::cout << "sub %esi, %ebx" << std::endl;
    std::cout << "push %ebx" << std::endl;
}

void CodeGenerator::visitTimesNode(TimesNode* node) {
    // WRITEME: Replace with code if necessary
    // #MULTIPLY
    node->expression_2->accept(this);
    node->expression_1->accept(this);

    std::cout << "pop %eax" << std::endl;
    std::cout << "pop %ecx" << std::endl;
    std::cout << "mul %ecx" << std::endl;
    std::cout << "push %eax" << std::endl;
    

}

void CodeGenerator::visitDivideNode(DivideNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
        
    std::cout << "mov $0, %edx" << std::endl;
    std::cout << "pop %eax" << std::endl;
    std::cout << "pop %ecx" << std::endl;
    std::cout << "div %ecx" << std::endl;
    std::cout << "push %eax" << std::endl;
}

void CodeGenerator::visitGreaterNode(GreaterNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
    std::string label_true = "GT_" + std::to_string(nextLabel());
    std::string label_end = "END_GT_" + std::to_string(nextLabel());


    std::cout << "pop %esi" << std::endl;
    std::cout << "pop %ebx" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "jg " << label_true << std::endl;
    std::cout << "push $0" << std::endl;
    std::cout << "jmp " << label_end << std::endl;
    std::cout << label_true << ":" << std::endl;
    std::cout << "push $1" << std::endl;
    std::cout << label_end << ":" << std::endl;


}

void CodeGenerator::visitGreaterEqualNode(GreaterEqualNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
    std::string label_true = "GTE_" + std::to_string(nextLabel());
    std::string label_end = "END_GTE_" + std::to_string(nextLabel());


    std::cout << "pop %esi" << std::endl;
    std::cout << "pop %ebx" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "jge " << label_true << std::endl;
    std::cout << "push $0" << std::endl;
    std::cout << "jmp " << label_end << std::endl;
    std::cout << label_true << ":" << std::endl;
    std::cout << "push $1" << std::endl;
    std::cout << label_end << ":" << std::endl;

}

void CodeGenerator::visitEqualNode(EqualNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
    std::string label_true = "GE_" + std::to_string(nextLabel());
    std::string label_end = "END_GE_" + std::to_string(nextLabel());


    std::cout << "pop %esi" << std::endl;
    std::cout << "pop %ebx" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "je " << label_true << std::endl;
    std::cout << "push $0" << std::endl;
    std::cout << "jmp " << label_end << std::endl;
    std::cout << label_true << ":" << std::endl;
    std::cout << "push $1" << std::endl;
    std::cout << label_end << ":" << std::endl;

}

void CodeGenerator::visitAndNode(AndNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
    std::string label_true = "AND_" + std::to_string(nextLabel());
    std::string label_end = "END_AND_" + std::to_string(nextLabel());


    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %esi" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "jne " << label_true << std::endl;
    std::cout << "push %ebx" << std::endl;
    std::cout << "jmp " << label_end << std::endl;
    std::cout << label_true << ":" << std::endl;
    std::cout << "push $0" << std::endl;
    std::cout << label_end << ":" << std::endl;

}

void CodeGenerator::visitOrNode(OrNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression_2->accept(this);
    node->expression_1->accept(this);
    std::string label_true = "OR_" + std::to_string(nextLabel());
    std::string label_end = "END_OR_" + std::to_string(nextLabel());

    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %esi" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "jne " << label_true << std::endl;
    std::cout << "push %ebx" << std::endl;
    std::cout << "jmp " << label_end << std::endl;
    std::cout << label_true << ":" << std::endl;
    std::cout << "push $1" << std::endl;
    std::cout << label_end << ":" << std::endl;

}

void CodeGenerator::visitNotNode(NotNode* node) {
    // WRITEME: Replace with code if necessary
    node->expression->accept(this);
    std::string label_true = "NOT_" + std::to_string(nextLabel());
    std::string label_end = "END_NOT_" + std::to_string(nextLabel());

    std::cout << "pop %ebx" << std::endl;
    std::cout << "mov $0, %esi" << std::endl;
    std::cout << "cmp %ebx, %esi" << std::endl;
    std::cout << "jne " << label_true << std::endl;
    std::cout << "push $1" << std::endl;
    std::cout << "jmp " << label_end << std::endl;
    std::cout << label_true << ":" << std::endl;
    std::cout << "push $0" << std::endl;
    std::cout << label_end << ":" << std::endl;
}

void CodeGenerator::visitNegationNode(NegationNode* node) {
    // WRITEME: Replace with code if necessary
    node->visit_children(this);

    std::cout << "pop %esi" << std::endl;
    std::cout << "mov $0, %ebx" << std::endl;
    std::cout << "sub %esi, %ebx" << std::endl;
    std::cout << "push %ebx" << std::endl;

}

void CodeGenerator::visitMethodCallNode(MethodCallNode* node) {
    // WRITEME: Replace with code if necessary
    
    MethodInfo m;

    std::cout << "push %eax" << std::endl;
    std::cout << "push %ecx" << std::endl;
    std::cout << "push %edx" << std::endl;


    if(node->expression_list->size() > 0){
        std::list<ExpressionNode*>::iterator it = node->expression_list->end();
        while(true){
            it--;
            (*it)->accept(this);
            if(it == (node->expression_list->begin())) break;
        }
    }
    // %eax, %ecx, and %edx

    //get object value
    std::string className;
    std::string methodName;
    if(node->identifier_2){
        methodName = node->identifier_2->name;
        className = node->identifier_1->objectClassName;
        m = (*(*classTable)[node->identifier_1->objectClassName].methods)[node->identifier_2->name];
        if(currentMethodInfo.variables->count(node->identifier_1->name) != 0){
            VariableInfo v = (*currentMethodInfo.variables)[node->identifier_1->name];
            std::cout << "push " << v.offset << "(%ebp)" << std::endl;
        }else{
            VariableInfo v = (*currentClassInfo.members)[node->identifier_1->name];
            std::cout << "mov 8(%ebp), %ebx" << std::endl;
            std::cout << "push " << v.offset << "(%ebx)" << std::endl;
        }
    }else{
        methodName = node->identifier_1->name;
        className = currentClassName;
        m = (*currentClassInfo.methods)[node->identifier_1->name];
        std::cout << "push 8(%ebp)" << std::endl;

    }
    std::cout << "call " << className << "_" << methodName << std::endl;
    std::cout << "add $" << m.parameters->size()*4 + 4 << ", %esp" << std::endl;
    std::cout << "pop %edx" << std::endl;
    std::cout << "pop %ecx" << std::endl;
    std::cout << "pop %ebx" << std::endl;
    

    if(m.returnType.baseType != bt_none){
        std::cout << "push %eax" << std::endl;
    }
    std::cout << "mov %ebx, %eax" << std::endl;


}

void CodeGenerator::visitMemberAccessNode(MemberAccessNode* node) {
    // WRITEME: Replace with code if necessary
        //CODE NEEDED HERE
        std::string var_name = node->identifier_1->name;
        std::string member_name = node->identifier_2->name;

        //get var_table of the class
        //check local vars, and class members
        

        if(currentMethodInfo.variables->count(var_name) != 0){
            VariableInfo v = (*currentMethodInfo.variables)[var_name];
            std::string className = v.type.objectClassName;
            
            VariableInfo target_var = (*(*classTable)[className].members)[member_name];   

            std::cout << "mov " << v.offset << "(%ebp), %ebx" << std::endl;
            std::cout << "push " << target_var.offset << "(%ebx)" << std::endl;

        }else{
            VariableInfo v = (*currentClassInfo.members)[var_name];
            std::string className = v.type.objectClassName;

            VariableInfo target_var = (*(*classTable)[className].members)[member_name];

            std::cout << "mov 8(%ebp), %ebx" << std::endl;
            std::cout << "push " << target_var.offset << "(%ebx)" << std::endl;


        }



}

void CodeGenerator::visitVariableNode(VariableNode* node) {
    // WRITEME: Replace with code if necessary
    if(currentMethodInfo.variables->count(node->identifier->name) != 0){
        
        VariableInfo v = (*currentMethodInfo.variables)[node->identifier->name];

        std::cout << "push " << v.offset << "(%ebp)" << std::endl;
    }else{
        VariableInfo v = (*currentClassInfo.members)[node->identifier->name];

        std::cout << "mov 8(%ebp), %ebx" << std::endl;
        std::cout << "push " << v.offset << "(%ebx)" << std::endl;
    }

}

void CodeGenerator::visitIntegerLiteralNode(IntegerLiteralNode* node) {
    // WRITEME: Replace with code if necessary
    node->visit_children(this);
}

void CodeGenerator::visitBooleanLiteralNode(BooleanLiteralNode* node) {
    // WRITEME: Replace with code if necessary
    node->visit_children(this);

}

void CodeGenerator::visitNewNode(NewNode* node) {
    // WRITEME: Replace with code if necessary
    ClassInfo c = (*classTable)[node->objectClassName];

    
    std::cout << "push $" << c.membersSize << std::endl;
    std::cout << "call malloc" << std::endl;
    std::cout << "add $4, %esp" << std::endl;
    if(c.methods->count(node->objectClassName)){
        if(node->expression_list->size() > 0){
            std::list<ExpressionNode*>::iterator it = node->expression_list->end();
            while(true){
                it--;
                (*it)->accept(this);
                if(it == (node->expression_list->begin())) break;
            }
        }
        std::cout << "push %eax" << std::endl;
        std::cout << "call " << node->objectClassName << "_" << node->objectClassName << std::endl;
        std::cout << "add $" << node->expression_list->size()*4+4 << ", %esp" << std::endl;
    }
    std::cout << "push %eax" << std::endl;
        
}

void CodeGenerator::visitIntegerTypeNode(IntegerTypeNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitBooleanTypeNode(BooleanTypeNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitObjectTypeNode(ObjectTypeNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitNoneNode(NoneNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitIdentifierNode(IdentifierNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitIntegerNode(IntegerNode* node) {
    // WRITEME: Replace with code if necessary
    std::cout << "push $" << node->value << std::endl;
    
}