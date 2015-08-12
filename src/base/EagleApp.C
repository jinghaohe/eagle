#include "EagleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<EagleApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

EagleApp::EagleApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  EagleApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  EagleApp::associateSyntax(_syntax, _action_factory);
}

EagleApp::~EagleApp()
{
}

void
EagleApp::registerApps()
{
  registerApp(EagleApp);
}

void
EagleApp::registerObjects(Factory & factory)
{
}

void
EagleApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
