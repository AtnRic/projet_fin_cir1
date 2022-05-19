anime({
  targets: [".first", ".last"],
  width: "0px",
  delay: function (el) {
    if (el.classList.contains("first")) {
      return 0;
    } else {
      return 3000;
    }
  },
  duration: 3000,
  loop: false,
  easing: "easeInOutQuad",
});
