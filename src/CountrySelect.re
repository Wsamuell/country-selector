open Bindings;
open CountryData;
open Icons;
open SharedStyle;

module Style = {
  let dropdown =
    ReactDOM.Style.make(
      ~position="relative",
      ~width="230px",
      ~height="429px",
      ~fontFamily="Arial",
      ~fontSize="14px",
      (),
    );
  let button =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~backgroundColor=colorToHex(Light),
      ~border=
        "1.5px solid var(--light-border-control-alpha, rgba(0, 0, 0, 0.20))",
      ~borderRadius="3px",
      ~columnGap="6px",
      ~display="flex",
      ~height="26px",
      ~justifyContent="space-between",
      ~minWidth="144px",
      ~padding="4px 10px",
      (),
    );
  let flag = ReactDOM.Style.make(~width="14px", ~height="14px", ());

  let divPad =
    ReactDOM.Style.make(
      ~padding="4px",
      ~textOverflow="ellipsis",
      ~overflow="hidden",
      ~maxWidth="150px",
      ~whiteSpace="nowrap",
      (),
    );
  let icon = {
    ReactDOM.Style.make(~padding="3px", ());
  };

  // Bring back blanket after fixing the dropdown
  let blanket = {
    ReactDOM.Style.make(
      ~position="fixed",
      ~bottom="0",
      ~left="0",
      ~right="0",
      ~top="0",
      ~zIndex="1",
      (),
    );
  };
  let menu = {
    ReactDOM.Style.make(
      ~position="absolute",
      ~width="100%",
      ~backgroundColor=colorToHex(Light),
      ~borderRadius="4px",
      ~boxShadow=
        "0px 3px 18px 0px rgba(0, 0, 0, 0.15), 0px 0px 0px 1px rgba(0, 0, 0, 0.08);",
      ~marginTop="4px",
      ~zIndex="2",
      (),
    );
  };
};
module CustomStyle = {
  open Select;
  let customStyle = {
    control: props =>
      ReactDOMStyle.combine(
        props,
        ReactDOMStyle.make(
          ~display="flex",
          ~flexDirection="row-reverse",
          ~borderRadius="2px 2px 0px 0px",
          ~borderColor=colorToHex(Grey),
          ~borderWidth="1.5px",
          ~padding="2px",
          (),
        ),
      ),
    menu: props =>
      ReactDOMStyle.combine(
        props,
        ReactDOMStyle.make(~borderRadius="0px 0px 2px 2px", ()),
      ),
  };
  let customTheme = {
    // colors:
    //   {
    //   primary: colorToHex(Hover),
    //     primary25: colorToHex(Hover),
    //   },
    spacing: {
      baseUnit: 5,
      controlHeight: 0,
      menuGutter: 2,
    },
  };
};

module Option = {
  module Style = {
    let optionFlag = ReactDOM.Style.make(~width="14%", ~height="14px", ());

    let flagStyles =
      ReactDOM.Style.make(
        ~display="flex",
        ~flexDirection="row",
        ~alignItems="center",
        ~justifyContent="space-between",
        ~padding="0px 6px",
        ~backgroundClip="padding-box",
        ~backgroundColor="initial",
        (),
      );

    let hoverStyles =
      ReactDOM.Style.make(~backgroundColor=colorToHex(Hover), ());

    let hoverFlagStyles = ReactDOM.Style.combine(flagStyles, hoverStyles);
    let unknownNumber = ReactDOM.Style.make(~color=colorToHex(Dark), ());
  };

  [@react.component]
  let make = (~internalProps, ~data) => {
    let (isHovered, setIsHovered) = React.useState(() => false);

    <div
      style={isHovered ? Style.hoverFlagStyles : Style.flagStyles}
      onMouseOver={_ => setIsHovered(_ => true)}
      onMouseOut={_ => setIsHovered(_ => false)}>
      <span className={"fi fi-" ++ data.value} style=Style.optionFlag />
      <Option props=internalProps />
      <div style=Style.unknownNumber> {React.string("0")} </div>
    </div>;
  };
};

module Menu = {
  [@react.component]
  let make = (~children) => {
    <div style=Style.menu> children </div>;
  };
};
module Blanket = {
  [@react.component]
  let make = (~onClick) => {
    <div onClick style=Style.blanket />;
  };
};

module Dropdown = {
  [@react.component]
  let make = (~target, ~children, ~isOpen, ~onClose) => {
    <div style=Style.dropdown>
      target
      {isOpen ? <Menu> children </Menu> : React.null}
      {isOpen ? <Blanket onClick=onClose /> : React.null}
    </div>;
  };
};

[@react.component]
let make = () => {
  let (active, setActive) = React.useState(() => false);
  let (countries, setCountries) =
    React.useState(() => countryLoadState(None));
  let (selectedCountry, setSelectedCountry) =
    React.useState(() => {label: "Select A country", value: "xx"});
  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray =>
               countryLoadState(Some(itemArray)) |> resolve
             )
          |> then_(array => setCountries(_ => array) |> resolve)
        );
      Some(() => ());
    },
    [||],
  );
  <Dropdown
    isOpen=active
    onClose={_ => setActive(_ => false)}
    target={
      <button onClick={_ => setActive(prev => !prev)} style=Style.button>
        <span className={"fi fi-" ++ selectedCountry.value} style=Style.flag />
        <div style=Style.divPad> {React.string(selectedCountry.label)} </div>
        <Arrow style=Style.icon />
      </button>
    }>
    <Select
      closeMenuOnSelect=true
      components={
        dropdownIndicator: _ => <Search />,
        indicatorSeparator: false,
        option: ({data} as internalProps: Select.optionProps) =>
          <Option internalProps data />,
      }
      multi=false
      name="Country Selector"
      noOptionsMessage={_ => "Country Not Found!"}
      onChange={value => setSelectedCountry(_ => value)}
      options=countries
      autoFocus=true
      backspaceRemovesValue=false
      controlShouldRenderValue=false
      hideSelectedOptions=false
      isClearable=false
      menuIsOpen=true
      placeholder="Search"
      tabSelectsValue=false
      theme=CustomStyle.customTheme
      styles=CustomStyle.customStyle
      value={selectedCountry.label}
    />
  </Dropdown>;
};
